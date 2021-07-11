#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

namespace algorithm::greedy
{
    int Solve(std::vector<std::pair<int, int> >& segments)
    {
        std::sort(segments.begin(), segments.end());

        int res = 0;
        int t = 0;
        for (const auto &seg : segments)
        {
            if (t < seg.second)
            {
                ++res;
                t = seg.first;
            }
        }

        return res;
    }
}

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<int> starts(n);
    std::vector<int> ends(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> starts.at(i);
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> ends.at(i);
    }

    std::vector<std::pair<int, int> > segments;
    for (int i = 0; i < n; ++i)
    {
        segments.push_back(std::make_pair(ends[i], starts[i]));
    }

    std::cout << algorithm::greedy::Solve(segments) << std::endl;

    return 0;
}