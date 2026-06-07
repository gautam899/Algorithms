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
    std::pair<std::vector<int>, std::vector<int>> find_shortest_path(size_t source, int V, std::vector<std::vector<Edge>> &graph)
    {
        std::vector<int> distance(V, INT_MAX);
        std::vector<int> prev(V, -1); // Keep track of the prevecessor. Once all the shortest path are achieved

        distance[source] = 0;

        // Perform the relaxation |V| - 1 times.
        for (size_t i = 0; i < V - 1; i++)
        {
            bool has_changed = false; // For early exit
            for (size_t u = 0; u < V; u++)
            {
                if (distance[u] != INT_MAX)
                {
                    for (const auto &edge : graph[u])
                    {
                        if (distance[u] + edge.weight < distance[edge.to])
                        {
                            distance[edge.to] = distance[u] + edge.weight;
                            prev[edge.to] = u;
                            has_changed = true;
                        }
                    }
                }
            }
            if (!has_changed)
                break;
        }

        // Check for a negative cycle
        for (size_t u = 0; u < V; u++)
        {
            for (auto &edge : graph[u])
            {
                if (distance[u] + edge.weight < distance[edge.to])
                {
                    // Negative cycle exist.
                    prev[edge.to] = u;

                    // Find a vertex on the negative cycle
                    std::vector<int> visited(V, 0);
                    visited[edge.to] = true;

                    // Run a while loop until we encounter a u that is already visited.
                    while (!visited[u])
                    {
                        visited[u] = true;
                        u = prev[u];
                    }

                    // Find the cycle.
                    std::vector<int> cycle;
                    cycle.push_back(u);
                    int v = prev[u];
                    while (v != u)
                    {
                        cycle.push_back(v);
                        v = prev[v];
                    }

                    fprintf(stderr, "Negative Cycle Detected\n");
                    for (auto it : cycle)
                    {
                        std::cout << it << " ";
                    }
                    std::cout << std::endl;
                    exit(1);
                }
            }
        }

        return {distance, prev};
    }
};

void build_path(int source, size_t destination, const std::vector<int> &prev)
{
    std::vector<int> path;
    int i = destination;
    while (destination != source)
    {
        path.push_back(destination);
        destination = prev[destination];
    }
    path.push_back(source);
    std::reverse(path.begin(), path.end());
    std::cout << "Shortest Path from " << source << " " << i << std::endl;
    for (const auto it : path)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
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
    auto [distance, prev] = sol.find_shortest_path(source, V, graph);

    std::cout << "Printing shortest path for all vertices from source\n";
    for (size_t i = 0; i < V; i++)
    {
        std::cout << source << "->" << i << ": " << distance[i] << std::endl;
    }

    std::vector<int> path;
    // Build Path
    for (size_t i = 0; i < V; i++)
    {
        build_path(source, i, prev);
    }
    return 0;
}