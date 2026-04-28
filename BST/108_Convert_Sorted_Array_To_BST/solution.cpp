#include <iostream>
#include <vector>
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
    TreeNode *helper(std::vector<int> &nums, int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, start, mid - 1);
        root->right = helper(nums, mid + 1, end);
        return root;
    }
    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        int n = nums.size();
        TreeNode *root = helper(nums, 0, n - 1);
        return root;
    }
};

int main()
{
    std::vector<int> v = {-10, -3, 0, 5, 9};
    Solution sol;
    TreeNode *root = sol.sortedArrayToBST(v);
    return 0;
}