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

    std::vector<std::uint32_t> sum_row(h);
    for (auto row_i = 0; row_i < h; ++row_i)
        sum_row[row_i] = std::accumulate(a[row_i].begin(), a[row_i].end(), 0);

    std::vector<std::uint32_t> sum_col(w);
    for (auto col_i = 0; col_i < w; ++col_i)
        sum_col[col_i] = std::accumulate(b[col_i].begin(), b[col_i].end(), 0);

    for (auto i = 0; i < h; ++i)
    {
        for (auto j = 0; j < w; ++j)
        {
            std::cout<< sum_row[i] + sum_col[j] - a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}