#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_set>
#include <limits.h>
class PRIMS
{
public:
    struct Comparator
    {
        bool operator()(std::pair<int, int> &a, std::pair<int, int> &b) const
        {
            return a.second < b.second;
        }
    };

    void find_mst(std::vector<std::vector<std::pair<int, int>>> &adj, size_t V)
    {
        std::vector<int> cheapestCost(V, INT_MAX); // keep track of minimum edge connecting to this vertex
        std::vector<int> cheapestEdge(V);

        auto cmp = [](const std::pair<int, int> &a, const std::pair<int, int> &b)
        {
            return a.second > b.second; // Smallest cost on the top
        };

        // Create a priorty queue with <node, cheapCost[vertex]>.
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> unexplored(cmp);
        std::unordered_set<int> explored; // Keep track of the explored vertices.

        int startV = 0;
        cheapestCost[startV] = 0;
        unexplored.push({startV, cheapestCost[startV]});

        while (unexplored.size())
        {
            // Take the unexplored vertex with minimum cost
            auto [v, w] = unexplored.top();
            unexplored.pop();

            if (explored.find(v) != explored.end())
            {
                // stale entry
                continue;
            }
            explored.insert(v); // mark explored.
            // Iterate all the outgoing edges from the vertex to node which are not the part of the tree yet.
            for (const auto [edge, weight] : adj[v]) // O(E). This for loop explore ever edge twice
            {
                // If the edge is unexplored
                if (explored.find(edge) == explored.end() && weight < cheapestCost[edge])
                {
                    cheapestCost[edge] = weight;
                    cheapestEdge[edge] = v; // The cheapest edge to edge.first is v.
                    unexplored.push({edge, weight});
                }
            }
        }
        int min_cost = 0;
        for (size_t i = 0; i < V; i++)
        {
            std::cout << "Cheapest edge to " << i << " is " << cheapestEdge[i] << " -> " << i << std::endl;
            std::cout << cheapestCost[i] << std::endl;
            min_cost += cheapestCost[i];
        }
        std::cout << "Minimum cost of the graph is " << min_cost << std::endl;
    }
};

int main()
{
    size_t V = 4;
    std::vector<std::vector<std::pair<int, int>>> adj(V);

    adj[0].push_back({1, 2});
    adj[0].push_back({3, 1});
    adj[1].push_back({0, 2});
    adj[1].push_back({3, 2});
    adj[3].push_back({0, 1});
    adj[3].push_back({1, 2});
    adj[3].push_back({2, 3});
    adj[2].push_back({3, 3});

    PRIMS helper;
    helper.find_mst(adj, V);

    // Time Complexity: O(E * LogV)
}