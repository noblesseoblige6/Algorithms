#include <bits/stdc++.h>

int main()
{
    std::uint32_t n, m;
    std::cin >> n >> m;

    using Point = std::pair<std::uint32_t, std::uint32_t>;
    Point start, goal;
    std::cin >> start.first >> start.second;
    std::cin >> goal.first >> goal.second;

    std::vector<std::vector<char>> map(n + 1, std::vector<char>(m + 1, '#'));
    for (auto i = 1; i <= n; ++i)
        for (auto j = 1; j <= m; ++j)
            std::cin >> map[i][j];

    std::vector<std::vector<std::int32_t>> distMap(n + 1, std::vector<std::int32_t>(m + 1, -1));
    distMap[start.first][start.second] = 0;
    std::queue<Point> queue;
    queue.push(start);
    while (!queue.empty())
    {
        auto const &p = queue.front();
        auto up = Point(p.first - 1, p.second);
        auto down = Point(p.first + 1, p.second);
        auto right = Point(p.first, p.second + 1);
        auto left = Point(p.first, p.second - 1);

        auto BFS = [](auto const &nextPoint, auto const &curPoint, auto const &map, auto &dm)
        {
            if (map[nextPoint.first][nextPoint.second] == '#')
                return false;

            if (dm[nextPoint.first][nextPoint.second] != -1)
                return false;

            dm[nextPoint.first][nextPoint.second] = dm[curPoint.first][curPoint.second] + 1;

            return true;
        };

        if (BFS(up, p, map, distMap))
            queue.push(up);
        if (BFS(down, p, map, distMap))
            queue.push(down);
        if (BFS(left, p, map, distMap))
            queue.push(left);
        if (BFS(right, p, map, distMap))
            queue.push(right);

        queue.pop();
    }

    std::cout << distMap[goal.first][goal.second] << std::endl;

    return 0;
}