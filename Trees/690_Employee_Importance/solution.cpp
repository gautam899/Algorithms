#include <vector>
#include <unordered_map>
// Definition for Employee.
class Employee
{
public:
    int id;
    int importance;
    std::vector<int> subordinates;
};

class Solution
{
public:
    void dfs(int id, std::unordered_map<int, Employee *> &mp, int &ans)
    {
        ans += mp[id]->importance;

        // Iterate the direct/indirect subordinates
        for (auto sub : mp[id]->subordinates)
        {
            dfs(sub, mp, ans);
        }
    }
    int getImportance(std::vector<Employee *> employees, int id)
    {
        std::unordered_map<int, Employee *> mp; // Using an unordered_map we would not have to iterate the employee vector in every dfs call.
        for (auto it : employees)
        {
            mp[it->id] = it;
        }
        int ans = 0;
        dfs(id, mp, ans);
        return ans;
    }
    // Time Complexity: In the worst case O(N)
};