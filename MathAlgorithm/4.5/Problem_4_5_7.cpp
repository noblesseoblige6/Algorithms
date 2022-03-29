#include <bits/stdc++.h>

namespace alg
{
    struct Vertex
    {
        std::vector<std::uint32_t> Edges;
        bool isVisited = false;
    };

    bool IsBinaryGraph(std::uint32_t n, std::uint32_t m, std::vector<std::pair<std::uint32_t, std::uint32_t>> const &edges)
    {
        std::vector<std::int32_t> dist(n + 1, -1);
        std::vector<Vertex> vertices(n + 1);
        for (auto const &e : edges)
        {
            vertices[e.first].Edges.push_back(e.second);
            vertices[e.second].Edges.push_back(e.first);
        }

        std::queue<std::uint32_t> q;
        dist[1] = 0;
        q.push(1);
        while (!q.empty())
        {
            auto v = q.front();
            for (auto v_next : vertices[v].Edges)
            {
                q.push(v_next);
                dist[v_next] = dist[v] + 1;
            }

            q.pop();
        }

        return true;
    }
}

int main()
{
    std::uint32_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<std::uint32_t, std::uint32_t>> edges(m);
    for (auto i = 0; i < m; ++i)
        std::cin >> edges[i].first >> edges[i].second;

    std::cout << (alg::IsBinaryGraph(n, m, edges) ? "Yes" : "No") << std::endl;

    return 0;
}