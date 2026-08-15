#include <iostream>
#include <vector>

// The intution behind morris preorder traversal is to establish links
// between node and it's inorder predecessor so that we can traverse the tree in pre-order.
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
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        // Morris Pre-order traveral
        std::vector<int> ans;
        if (!root)
        {
            return ans;
        }
        TreeNode *curr = root;
        TreeNode *prev;
        while (curr)
        {
            // Printing the curr here will not be the right choice as curr can be visited twice.
            // If the curr node does not have a left, the curr node is the next preorder node in the order.
            // So we print the node and move right.
            if (!curr->left)
            {
                // Print the curr and move right.
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                // If the curr node has a left, our goal is connect the current node to it's inorder predecessor.
                // To do that we need to go to the right most node of the left subtree of the curr, while keeping track of curr.
                // So, we use a prev pointer pointing to curr->left.
                prev = curr->left;

                // Move prev as right as possible. To make sure we do not end up in loop(as we link curr with it's inorder predecessor, which is the right most
                // node of the left subtree of curr), we put a check if prev->right != curr.
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }

                // At this point if prev->right is NULL that means curr is being visited the first time. If it was otherwise
                // i.e. the prev->right != NULL, that would have meant the link has already been made. In that case we would have said the
                // left subtree of curr node is iterated completely and it's time to move right.
                if (!prev->right)
                {
                    // Curr is being visited the first time.
                    ans.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    // Left tree done. Restore the links and move to curr->right.
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    std::vector<int> ans = sol.preorderTraversal(node1);
    for (auto it : ans)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return 0;
}