#include <vector>
#include <unordered_map>
#include <iostream>

class Codec
{
public:
    void dfs(std::unordered_map<int, std::vector<int>> &mp, std::vector<int> &ans, int kill_id)
    {
        ans.push_back(kill_id);

        for (auto it : mp[kill_id])
        {
            dfs(mp, ans, it);
        }
    }

    void killProcess(std::vector<int> &pid, std::vector<int> &ppid, int kill_id)
    {
        std::unordered_map<int, std::vector<int>> mp;

        for (std::size_t i = 0; i < pid.size(); i++)
        {
            mp[ppid[i]].push_back(pid[i]);
        }

        if (mp.find(kill_id) == mp.end())
        {
            std::cout << "Invalid Process Id" << std::endl;
            std::exit(1);
        }

        std::vector<int> ans;
        dfs(mp, ans, kill_id);

        for (auto it : ans)
        {
            std::cout << it << " ";
        }
        std::cout << std::endl;
    }
};
int main()
{
    std::vector<int> pid = {1, 3, 10, 5};
    std::vector<int> ppid = {3, 0, 5, 3};
    Codec code;
    int kill_id = -1;
    code.killProcess(pid, ppid, kill_id);
    return 0;

    // Time complexity: O(N)-> Construct the graph. O(N) for DFS traversal.
    // To avoid a stack overflow, we can also code it in an iterative manner.
}