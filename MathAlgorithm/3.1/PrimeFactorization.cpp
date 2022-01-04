#include <iostream>
#include <vector>
#include <cmath>

bool IsPrime(std::int64_t num)
{
    if(num <= 1)
        return false;

    for (decltype(num) i = 2; i*i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

std::vector<std::int64_t> PrimeFactorization(std::int64_t num)
{
    std::vector<std::int64_t> primes;
    for (decltype(num) i = 2; i * i <= num; ++i)
    {
        while (num % i == 0)
        {
            num /= i;
            primes.push_back(i);
        }
    }

    if(num >= 2)
        primes.push_back(num);

    return primes;
}

int main()
{
    std::int64_t num;
    std::cin >> num;

    auto res = PrimeFactorization(num);
    for (auto num : res)
        std::cout << num << std::endl;

    return 0;
}