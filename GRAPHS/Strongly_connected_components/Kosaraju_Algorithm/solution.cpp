#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    // function to perform dfs traversal.
    void dfs(int start, std::vector<std::vector<int>> &adj, std::vector<int> &visited, std::vector<int> &order)
    {
        visited[start] = 1;
        for (auto neighbor : adj[start])
        {
            if (visited[neighbor] == 0)
            {
                dfs(neighbor, adj, visited, order);
            }
        }
        order.push_back(start);
    }

    // Input: adj list for the graph
    // Output: Components -- The strongly connected components of G
    // Output: adj-cond -- Adjacency list of Condensation Graph.
    void strongly_connected_component(int V, std::vector<std::vector<int>> &adj, std::vector<std::vector<int>> &components, std::vector<std::vector<int>> &adj_cond)
    {
        std::vector<int> visited(V, 0);
        std::vector<int> order;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, adj, visited, order);
            }
        }

        // Order vector now contains nodes in the order of their increasing exit time.
        // for (auto it : order)
        // {
        //     std::cout << it << " ";
        // }
        // std::cout << "\n";

        // Create a transpose graph
        std::vector<std::vector<int>> adj_transpose(V);
        for (int v = 0; v < V; v++)
        {
            for (auto u : adj[v])
            {
                adj_transpose[u].push_back(v);
            }
        }
        // Reverse the order vector to start with vertices in decreasing order of their exit time. This is because, we would want to start
        // from the vertex belonging to the "root" SCC. i.e the SCC with no incoming edge after the transpose.
        std::reverse(order.begin(), order.end());
        std::vector<int> component;
        std::vector<int> roots(V);

        visited.assign(visited.size(), 0);
        for (auto u : order)
        {
            if (!visited[u])
            {
                dfs(u, adj_transpose, visited, component);
                components.push_back(component);
                int root = *component.begin();
                for (auto v : component)
                {
                    roots[v] = root;
                }
                component.resize(0);
            }
        }
        // for (auto it : roots)
        // {
        //     std::cout << it << " ";
        // }
        // std::cout << "\n";
        // int count = 1;
        // for (int i = 0; i < components.size(); i++)
        // {
        //     std::cout << "Component: " << count << std::endl;
        //     for (int j = 0; j < components[i].size(); j++)
        //     {
        //         std::cout << components[i][j] << " ";
        //     }
        //     std::cout << "\n";
        //     count++;
        // }

        adj_cond.assign(V, {});
        // Create edges b/w SCC to form a condensation graph
        for (int v = 0; v < V; v++)
        {
            for (auto u : adj[v])
            {
                if (roots[u] != roots[v])
                {
                    adj_cond[roots[u]].push_back(roots[v]); // Create edge b/w roots of the two components.
                }
            }
        }
    }

    void solve(int V, std::vector<std::vector<int>> &adj)
    {
        std::vector<std::vector<int>> components;
        std::vector<std::vector<int>> adj_cond;

        strongly_connected_component(V, adj, components, adj_cond);
    }
};
int main()
{
    int V = 10;
    std::vector<std::vector<int>> graph(V);
    graph[0].push_back(1);
    graph[0].push_back(7);
    graph[1].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(5);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(9);
    graph[5].push_back(3);
    graph[5].push_back(6);
    graph[5].push_back(9);
    graph[6].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);
    graph[7].push_back(0);
    graph[8].push_back(6);
    graph[8].push_back(9);
    graph[9].push_back(4);

    // The above graph created is the one in the image attached into the README.
    Solution sol;
    sol.solve(V, graph);
    return 0;
}