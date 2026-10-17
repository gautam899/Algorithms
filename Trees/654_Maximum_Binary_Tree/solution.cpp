#include <iostream>
#include <vector>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode()
    {
        val = 0;
    }

    TreeNode(int _val)
    {
        val = _val;
    }

    TreeNode(int _val, TreeNode *_left, TreeNode *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Codec
{
public:
    TreeNode *dfs(std::vector<int> &nums, int start, int end)
    {
        if (start > end)
            return nullptr;

        int maxInd = start;
        int maxVal = nums[start];

        for (int i = start; i <= end; i++)
        {
            if (nums[i] > maxVal)
            {
                maxVal = nums[i];
                maxInd = i;
            }
        }

        TreeNode *root = new TreeNode(maxVal);

        root->left = dfs(nums, start, maxInd - 1);
        root->right = dfs(nums, maxInd + 1, end);
        return root;
    }
    TreeNode *maxBinaryTree(std::vector<int> &nums)
    {
        int n = nums.size();
        return dfs(nums, 0, n - 1);
    }
};
int main()
{
    return 0;
}