#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

class Solution
{
public:
    void find_shortest_path(int source, std::vector<std::vector<std::pair<int, int>>> &graph, std::vector<int> &dist, std::vector<int> &prev)
    {
        dist[source] = 0;
        prev[source] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({dist[source], source}); // start with the source.

        while (!pq.empty())
        {
            // Pop the node with the minimum distance
            std::pair<int, int> p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
            if (d > dist[node])
                continue;
            // Visit the neighbors
            for (const auto &[next, weight] : graph[node])
            {
                // neighbor: {node, edge_weight/dist}
                if (d + weight < dist[next])
                {
                    dist[next] = d + weight;
                    prev[next] = node;
                    pq.push({dist[next], next});
                }
            }
        }
    }
};
int main()
{
    // Create a weighted graph
    int V = 7;
    std::vector<std::vector<std::pair<int, int>>> graph(V, std::vector<std::pair<int, int>>());
    graph[0].push_back({3, 4}); // 0--->3 weight 4
    graph[0].push_back({4, 4}); // 0--->2 weight 4
    graph[0].push_back({2, 4}); // 0--->2 weight 4
    graph[1].push_back({2, 2}); // 1--->2 weight 2
    graph[1].push_back({5, 2}); // 1--->5 weight 2
    graph[2].push_back({0, 3});
    graph[2].push_back({1, 2});
    graph[2].push_back({4, 4});
    graph[2].push_back({6, 5});
    graph[3].push_back({0, 4});
    graph[3].push_back({4, 2});
    graph[4].push_back({3, 2});
    graph[4].push_back({0, 4});
    graph[4].push_back({2, 4});
    graph[4].push_back({6, 5});
    graph[5].push_back({1, 2});
    graph[5].push_back({6, 5});
    graph[6].push_back({4, 5});
    graph[6].push_back({2, 5});
    graph[6].push_back({5, 5});

    Solution sol;
    std::vector<int> dist(V, INT_MAX);
    std::vector<int> prev(V, -1); // Initially prev of every node is undefined.
    sol.find_shortest_path(0, graph, dist, prev);

    for (int i = 0; i < prev.size(); i++)
    {
        std::cout << prev[i] << " ";
    }
    std::cout << "\n";

    // Print the shorted Path from the source to all the node
    std::vector<int> path;
    for (size_t i = 1; i < V; i++)
    {
        // i is the target node.
        size_t target = i;
        if (prev[target] != -1)
        {
            while (target != 0)
            {
                path.push_back(target);
                target = prev[target];
            }
            path.push_back(target);
        }
        std::cout << "Shortest Path to target: " << i << "\n";
        std::reverse(path.begin(), path.end());
        for (auto it : path)
        {
            std::cout << it << " ";
        }
        std::cout << "\n";
        path.clear();
    }
}