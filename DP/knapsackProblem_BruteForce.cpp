#include <iostream>
#include <vector>

namespace DP
{
    int Solve(int n, int w, const std::vector<std::pair<int, int>>& items)
    {
        // no items
        if (n == static_cast<int>(items.size()))
        {
            return 0;
        }
        // weight over
        else if (w < items[n].first)
        {
            return Solve(n + 1, w, items);
        }

        return std::max(Solve(n + 1, w, items), Solve(n + 1, w - items[n].first, items) + items[n].second);
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> items;
    for (int i = 0; i < n; ++i)
    {
        int weight, value;
        std::cin >> weight >> value;
        items.emplace_back(weight, value);
    }

    int w;
    std::cin >> w;
    std::cout << DP::Solve(0, w, items) << std::endl;
    return 0;
}