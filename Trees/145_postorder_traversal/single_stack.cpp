#include <iostream>
#include <vector>
#include <stack>

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
    std::vector<int> postorderTraversal(TreeNode *root)
    {
        std::vector<int> ans;
        if (!root)
        {
            return ans;
        }
        TreeNode *curr = root;
        TreeNode *lastVis = NULL; // To keep track of when to move right.
        TreeNode *peekNode = NULL;
        std::stack<TreeNode *> st;
        while (curr || !st.empty())
        {
            if (curr)
            {
                // Push to the stack and move to the left
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                peekNode = st.top();
                // If the right of the stack top has not been processed yet.
                if (peekNode->right && peekNode->right != lastVis)
                {
                    curr = peekNode->right;
                }
                else
                {
                    // If the right of the stack top has been processed then we can print the
                    // node and mark it as our last visited node. At this point the node's left and right and itself
                    // Both are processed, so we can now remove it from the stack top.
                    ans.push_back(peekNode->val);
                    lastVis = peekNode;
                    st.pop();
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
    std::vector<int> ans = sol.postorderTraversal(node1);
    for (auto it : ans)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return 0;
    // T.C: O(N)
    // S.C: O(N)
}