#include <iostream>
#include <vector>
#include <queue>

class Solution
{
public:
    // The intution behind solving this problem is using the concept of topological sort. i.e for any edge(u,v) b/w vertices u and v, u must comes
    // before v. Topological sort is not possible if there is a cycle in the directed graph. Upon observing, we can say that completing all the course is
    // possible if there is topological sort possible, i.e if there is no cycle. We cannot have a toposort if there is a cycle in the graph.

    // Kahn's algorithm
    bool canFinish(std::vector<std::vector<int>> &course, int num_courses)
    {
        // Create a adjacency list.
        std::vector<std::vector<int>> adj(num_courses); // O(V+E)
        std::vector<int> indegree(num_courses, 0);      // O(E)
        for (auto it : course)                          // O(E)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        std::vector<int> finished_courses;
        std::queue<int> q;
        // We start with indegree zero. These are the courses that have no dependencies.
        for (int i = 0; i < num_courses; i++) // O(V)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                finished_courses.push_back(i);
            }
        }
        while (!q.empty()) // O(V)
        {
            int x = q.front();
            q.pop();
            // Visit the neighbors
            for (auto it : adj[x])
            {
                if (--indegree[it] == 0)
                {
                    q.push(it);
                    finished_courses.push_back(x);
                }
            }
        }
        return finished_courses.size() == num_courses;

        // T.C = O(V+E)
        // S.C = O(V+E)
    }
};

int main()
{
    std::vector<std::vector<int>> courses = {{0, 1}};
    Solution sol;
    bool ans = sol.canFinish(courses, 2);
    std::cout << ans << "\n";
    return 0;
}