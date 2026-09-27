#include <unordered_map>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    using ll = long long;
    int dfs(TreeNode *root, ll currSum, int targetSum,
            std::unordered_map<ll, int> &mp)
    {
        if (!root)
            return 0;

        int count = 0;
        currSum += root->val;
        if (mp.find(currSum - targetSum) != mp.end())
            count += mp[currSum - targetSum];
        mp[currSum]++;
        count += dfs(root->left, currSum, targetSum, mp);
        count += dfs(root->right, currSum, targetSum, mp);
        mp[currSum]--; // backtrack.

        return count;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;

        std::unordered_map<ll, int> mp;
        mp[0]++;
        int currSum = 0;
        return dfs(root, currSum, targetSum, mp);
    }
};