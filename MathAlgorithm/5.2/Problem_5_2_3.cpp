#include <bits/stdc++.h>

int main()
{
    std::uint32_t n;
    std::uint64_t k;
    std::cin >> n >> k;

    std::vector<std::uint32_t> dests(n+1, 0);
    std::copy_n(std::istream_iterator<std::uint32_t>{std::cin}, n, dests.begin()+1);

    std::vector<std::int32_t> first(n+1, -1);
    std::vector<std::int32_t> second(n + 1, -1);

    std::uint32_t u = 1;
    std::uint32_t count = 0;
    while(true)
    {
        // no loop
        if (count == k)
        {
            std::cout << u << std::endl;
            break;
        }

        // loop
        if (first[u] == -1)
            first[u] = count;
        else if (second[u] == -1)
            second[u] = count;

        if (first[u] != -1 && second[u] != -1)
        {
            if ((k - first[u]) % (second[u] - first[u]) == 0)
            {
                std::cout << u << std::endl;
                break;
            }
        }

        u = dests[u];
        count++;
    }
    return 0;
}