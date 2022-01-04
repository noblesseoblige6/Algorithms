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
    for (decltype(num) i = 1; i * i <= num; ++i)
    {
        if (IsPrime(i))
            primes.push_back(i);

        auto tmp = static_cast<std::int64_t>(num / i);
        if (IsPrime(tmp))
            primes.push_back(tmp);
    }

    std::vector<std::int64_t> res;
    auto tmp = num;
    while (tmp != 1)
    {
        for (auto prime : primes)
        {
            if (tmp % prime == 0)
            {
                tmp /= prime;
                res.push_back(prime);
                break;
            }
        }
    }

    return res;
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