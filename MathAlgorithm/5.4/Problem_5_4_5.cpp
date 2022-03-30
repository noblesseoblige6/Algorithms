#include <bits/stdc++.h>

int main()
{
    std::uint32_t n, k;
    std::cin >> n >> k;

    std::vector<std::uint32_t> v(k);
    std::copy_n(std::istream_iterator<std::uint64_t>{std::cin}, v.size(), v.begin());

    std::vector<bool> isMultiple(n+1, false);
    for (decltype(n) i = 1; i <= n; ++i)
    {
        for(auto val : v)
        {
            if (i % val != 0)
                continue;

            isMultiple[i] = true;
        }
    }

    std::uint32_t res = 0;
    for (auto isMul : isMultiple)
        res += (isMul ? 1 : 0);

    std::cout << res << std::endl;

    return 0;
}