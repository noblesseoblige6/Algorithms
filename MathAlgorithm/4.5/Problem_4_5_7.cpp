#include <bits/stdc++.h>

namespace alg
{
    bool IsBipartiteGraph(std::uint32_t n, std::uint32_t m, std::vector<std::pair<std::uint32_t, std::uint32_t>> const &edges)
    {
        std::vector<std::int32_t> dist(n + 1, -1);

        struct Vertex
        {
            std::vector<std::uint32_t> Edges;
            bool isVisited = false;
        };
        std::vector<Vertex> vertices(n + 1);
        for (auto const &e : edges)
        {
            vertices[e.first].Edges.push_back(e.second);
            vertices[e.second].Edges.push_back(e.first);
        }

        std::queue<std::uint32_t> q;
        for (decltype(n) i = 1; i <= n; ++i)
        {
            if (dist[i] != -1)
                continue;

            dist[i] = 0;
            q.push(i);

            while (!q.empty())
            {
                auto v = q.front();
                q.pop();

                for (const auto &v_next : vertices[v].Edges)
                {
                    if (dist[v_next] != -1)
                        continue;

                    q.push(v_next);
                    dist[v_next] = dist[v] + 1;
                }
            }
        }

        for (auto const &edge : edges)
        {
            if (dist[edge.first] == dist[edge.second])
                return false;
        }

        return true;
    }
}

int main()
{
    std::uint32_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<std::uint32_t, std::uint32_t>> edges(m);
    for (decltype(m) i = 0; i < m; ++i)
        std::cin >> edges[i].first >> edges[i].second;

    std::cout << (alg::IsBipartiteGraph(n, m, edges) ? "Yes" : "No") << std::endl;

    return 0;
}