#include <iostream>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {};
};

// In order to solve this problem in most optimal way, we can use morris order traversal.
// In morris order traversal, we keep the curr at the root and visit the right most node of the left
// subtree and then re-wire. And since the flattened tree must match the pre-order traversal of the node,
// the right most node of the left tree will point to the right of the curr, and along with that the curr->right points to curr->left, and
// finally curr->left to null.
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        TreeNode *curr = root;
        TreeNode *prev;
        while (curr)
        {
            if (curr->left)
            {
                prev = curr->left;
                while (prev->right)
                {
                    prev = prev->right;
                }

                if (!prev->right)
                {
                    // Connect the prev->right to curr->right as that would be it's preorder successor.
                    prev->right = curr->right;
                    // curr's right goes to curr's left and
                    curr->right = curr->left;
                    curr->left = NULL;
                }
            }
            curr = curr->right;
        }
        return;
    }
};

int main()
{
    // TODO: Create a Tree.
    return 0;
}
