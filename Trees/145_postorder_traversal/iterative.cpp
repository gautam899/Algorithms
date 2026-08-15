#include <iostream>
#include <vector>
#include <stack>
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
    std::vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        std::stack<TreeNode *> st;
        std::vector<int> ans;
        TreeNode *curr = root;
        st.push(curr);
        while (!st.empty())
        {
            curr = st.top();
            ans.push_back(curr->val);
            st.pop();
            if (curr->left)
                st.push(curr->left);
            if (curr->right)
                st.push(curr->right);
        }
        std::reverse(ans.begin(), ans.end());
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