#pragma once

namespace acLib
{
    using namespace std;

    template <typename T>
    void acIFConvertNumberDataToStr(AC_PROPERTY_TYPE type, T data, string& val);

    template <typename T>
    T acIFConvertStrToNumberData(AC_PROPERTY_TYPE type, const string& val);

    template <typename T>
    void acIFConvertNumberDataToStr(AC_PROPERTY_TYPE type, T data, string& val)
    {
        ostringstream oss;

        switch (type)
        {
        case AC_PROPERTY_TYPE_BOOL:
            val = data ? "True" : "False";
            break;
        case AC_PROPERTY_TYPE_INT:
        case AC_PROPERTY_TYPE_FLOAT:
        case AC_PROPERTY_TYPE_DOUBLE:
            oss << data;
            val = oss.str();
            break;
        default:
            val = "";
            break;
        }
    }

    template <typename T>
    T acIFConvertStrToNumberData(AC_PROPERTY_TYPE type, const string& val)
    {
        istringstream iss(val);
        T res = T();
        switch (type)
        {
        case AC_PROPERTY_TYPE_BOOL:
            res = (val == "True");
            break;
        case AC_PROPERTY_TYPE_INT:
        case AC_PROPERTY_TYPE_FLOAT:
        case AC_PROPERTY_TYPE_DOUBLE:
            iss >> res;
            break;
        default:
            break;
        }

        return res;
    }
}
