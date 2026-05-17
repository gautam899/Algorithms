#include <iostream>
#include <vector>

class Solution
{
public:
    bool dfs(int node, std::vector<std::vector<int>> &adj, std::vector<int> &visited)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (visited[it] == 1)
            {
                return false; // has cycle, cannot finish all the courses.
            }
            else if (visited[it] == 0)
            {
                if (!dfs(it, adj, visited))
                {
                    return false;
                }
            }
        }
        //
        visited[node] = 2; // Mark it done.
        return true;
    }
    bool canFinish(std::vector<std::vector<int>> &courses, int numCourses)
    {
        std::vector<int> visited(numCourses, 0);
        // Create a adjacency list
        std::vector<std::vector<int>> adj(numCourses);
        for (auto it : courses)
        {
            adj[it[1]].push_back(it[0]);
        }

        // visited = 0 -> not visited
        // visited = 1 -> visiting
        // visited = 2 -> visited
        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0)
            {
                if (!dfs(i, adj, visited))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    std::vector<std::vector<int>> courses = {{0, 1}, {1, 0}};
    Solution sol;
    bool ans = sol.canFinish(courses, 2);
    std::cout << ans << "\n";
    return 0;
}