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
    TreeNode *merge(TreeNode *root1, TreeNode *root2)
    {
        if (root1 && root2) // If both root's are not null, add them
            root1->val = root1->val + root2->val;
        else if (!root1 && root2) // If root1 is null but root2 is not. Create new node with root2 value and point root2 to it.
            root1 = new TreeNode(root2->val);
        else if (root1 && !root2)
            return root1;
        else
            return nullptr;

        root1->left = merge(root1->left, root2->left);
        root1->right = merge(root1->right, root2->right);
        return root1;
    }
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        return merge(root1, root2);
    }
    // Time Complexity: O(N+M).
};

int main()
{
}