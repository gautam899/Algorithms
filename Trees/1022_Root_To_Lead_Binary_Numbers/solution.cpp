#include <iostream>
#include <vector>
#include <algorithm>

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
    int dfs(TreeNode *root, int sum)
    {
        if (!root)
            return 0;
        sum = sum * 2 + root->val; // Left shift and add the value
        return (!root->left && !root->right) ? sum : dfs(root->left, sum) + dfs(root->right, sum);
    }
    int sumRootToLeaf(TreeNode *root)
    {

        return dfs(root, 0);
    }
    // T.C: O(N)
};

int main()
{
}