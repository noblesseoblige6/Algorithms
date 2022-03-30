#include <bits/stdc++.h>

int main()
{
    std::uint32_t w, h;
    std::cin >> h >> w;

    std::vector<std::vector<std::uint32_t>> a(h, std::vector<std::uint32_t>(w));
    std::vector<std::vector<std::uint32_t>> b(w, std::vector<std::uint32_t>(h));
    for (auto i = 0; i < h; ++i)
    {
        for (auto j = 0; j < w; ++j)
        {
            std::cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }

    std::vector<std::uint32_t> sum_h(h);
    for (auto i = 0; i < h; ++i)
        sum_h[i] = std::accumulate(a[i].begin(), a[i].end(), 0);

    std::vector<std::uint32_t> sum_w(w);
    for (auto i = 0; i < w; ++i)
        sum_w[i] = std::accumulate(b[i].begin(), b[i].end(), 0);

    for (auto i = 0; i < h; ++i)
    {
        for (auto j = 0; j < w; ++j)
        {
            std::cout<< sum_h[i] + sum_w[j] - a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}