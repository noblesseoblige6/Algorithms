#include<iostream>
#include<cstdio>
#include<cstring>
#include <stdint.h>

using namespace std;

typedef uint8_t         BYTE;

class CRC16
{
public:
    static uint16_t s_polynomial;
    static uint16_t s_crc16Table[256];

    static void CreateCRCTable();
    static uint16_t CalcCRC(const BYTE* data, const int size);

private:
    CRC16() {};
};

//@comment Polynomial for right shift
uint16_t CRC16::s_polynomial = 0xa001;

uint16_t CRC16::s_crc16Table[256] = { 0 };

void CRC16::CreateCRCTable()
{
    for (int i = 0; i < 256; ++i)
    {
        uint16_t crc = static_cast<uint16_t>(i);
        for (int j = 0; j < 8; ++j)
        {
            // 最下位ビットが1のときは剰余結果が必ず0になるので、1bitシフトしてxorを計算する
            crc = (crc & 1) ? (crc >> 1) ^ s_polynomial  : crc >> 1;
        }
        s_crc16Table[i] = crc;
    }
}

uint16_t CRC16::CalcCRC(const BYTE* data, const int size)
{
    uint16_t crc = 0;
    for (int i = 0; i < size; ++i)
    {
        crc = s_crc16Table[(crc ^ data[i]) & 0xFF] ^ crc >> 8;
    }
    return crc;
}

class CRC32
{
public:
    static uint32_t s_polynomial;
    static uint32_t s_crc32Table[256];

    static void CreateCRCTable();
    static uint32_t CalcCRC(const BYTE* data, const int size);

private:
    CRC32() {};
};

// polynomial for right shift
uint32_t CRC32::s_polynomial = 0xedb88320;

uint32_t CRC32::s_crc32Table[256] = { 0 };

void CRC32::CreateCRCTable()
{
    for (int i = 0; i < 256; ++i)
    {
        uint32_t crc = static_cast<uint32_t>(i);
        for (int j = 0; j < 8; ++j)
        {
            // 最下位ビットが1のときは剰余結果が必ず0になるので、1bitシフトしてxorを計算する
            crc = (crc & 1) ? (crc >> 1) ^ s_polynomial : crc >> 1;
        }
        s_crc32Table[i] = crc;
    }
}

uint32_t CRC32::CalcCRC(const BYTE* data, const int size)
{
    uint32_t crc = 0x00000000;
    for (int i = 0; i < size; ++i)
    {
        crc = s_crc32Table[(crc ^ data[i]) & 0xFF] ^ crc >> 8;
    }

    return crc;
}

int main()
{
    CRC16::CreateCRCTable();
    CRC32::CreateCRCTable();

    char buf[256] = "This is a test case";
    int sz = strlen(buf);

    printf("Original Data: ");
    for (int i = 0; i < sz; ++i)
    {
        printf(" %x", buf[i]);
    }
    printf("\n");
    uint16_t testCRC16 = CRC16::CalcCRC((BYTE*)buf, sz);
    uint32_t testCRC32 = CRC32::CalcCRC((BYTE*)buf, sz);

    printf("Data CRC16 : %x\n", testCRC16);
    printf("Data CRC32 : %x\n", testCRC32);
// CRCを付加してさらにCRCを求めると0になるはず
    int orgSz = sz;
    memcpy(buf+orgSz, &testCRC16, sizeof(testCRC16));
    sz = strlen(buf);

    testCRC16 = CRC16::CalcCRC((BYTE*)buf, sz);
    printf("Data CRC16 : %x\n", testCRC16);

    memcpy(buf+orgSz, &testCRC32, sizeof(testCRC32));
    sz = strlen(buf);

    testCRC32 = CRC32::CalcCRC((BYTE*)buf, sz);
    printf("Data CRC32 : %x\n", testCRC32);

    return 0;
}