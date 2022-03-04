#include <bits/stdc++.h>

int main()
{
    std::uint32_t t, n;
    std::cin >> t >> n;

    std::vector<std::pair<std::uint32_t, std::uint32_t>> times(n, {0, 0});
    for (auto &time : times)
        std::cin >> time.first >> time.second;

    std::vector<std::int64_t> diffs(t+1, 0);

    for (decltype(n) i = 0; i < n; ++i)
    {
        diffs[times[i].first] += 1;
        diffs[times[i].second] -= 1;
    }

    std::vector<std::int64_t> cusums(t+1, diffs[0]);
    for (decltype(n) i = 1; i < t; ++i)
        cusums[i] = diffs[i] + cusums[i-1];

    for (decltype(n) i = 0; i < t; ++i)
       std::cout << cusums[i] << std::endl;
}