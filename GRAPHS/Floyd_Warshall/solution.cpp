#include <vector>
#include <iostream>
#include <utility>
#include <limits.h>
#include <algorithm>

struct Edge
{
    int to;
    int weight;
};

class Solution
{
public:
    std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> find_shortest_path(size_t source, int V, std::vector<std::vector<Edge>> &graph)
    {
        std::vector<std::vector<int>> dist(V, std::vector<int>(V, INT_MAX));
        std::vector<std::vector<int>> prev(V, std::vector<int>(V, 0));

        for (size_t u = 0; u < V; u++)
        {
            for (const auto &edge : graph[u])
            {
                dist[u][edge.to] = edge.weight;
                prev[u][edge.to] = u;
            }
        }

        for (size_t u = 0; u < V; u++)
        {
            dist[u][u] = 0;
            prev[u][u] = u;
        }

        for (size_t k = 0; k < V; k++) // Intermidiate Nodes.
        {
            for (size_t i = 0; i < V; i++)
            {
                for (size_t j = 0; j < V; j++)
                {
                    if (dist[i][j] < (dist[i][k] + dist[k][j]))
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        prev[i][j] = prev[k][j];
                    }

                    // or
                    // dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        return {dist, prev};
    }
};

void build_path(int source, size_t destination, std::vector<int> &path, const std::vector<std::vector<int>> &prev)
{
    if (prev[source][destination] == 0)
        return;

    path.push_back(destination);
    while (source != destination)
    {
        destination = prev[source][destination];
        path.push_back(destination);
    }
}

int main()
{
    int V = 5;
    std::vector<std::vector<Edge>> graph(V);
    graph[0].push_back({1, 6});
    graph[0].push_back({2, 7});
    graph[1].push_back({3, 5});
    graph[1].push_back({2, 8});
    graph[1].push_back({4, -4});
    graph[2].push_back({3, -3});
    graph[2].push_back({4, 9});
    graph[3].push_back({1, -2});
    graph[4].push_back({0, 2});
    graph[4].push_back({3, 7});

    Solution sol;
    size_t source = 1;
    const auto [distance, prev] = sol.find_shortest_path(source, V, graph);

    std::cout << "Printing shortest path for all vertices from source\n";
    for (size_t i = 0; i < V; i++)
    {
        for (size_t j = 0; j < V; j++)
        {
            std::cout << "Shortest Distance b/w " << i << " and " << j << " is " << distance[i][j] << std::endl;
        }
    }

    for (size_t i = 0; i < V; i++)
    {
        for (size_t j = 0; j < V; j++)
        {
            if (distance[i][j] != INT_MAX)
            {
                std::vector<int> path;
                build_path(i, j, path, prev);
                std::cout << "Shortest Path b/w " << i << " and " << j << " is " << std::endl;
                for (size_t k = 0; k < path.size(); k++)
                {
                    std::cout << path[k] << " ";
                }
                std::cout << std::endl;
            }
        }
    }

    return 0;
}