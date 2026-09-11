#include <iostream>
#include <vector>
#include <stack>

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

class Solution
{
public:
    std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return {};
        std::vector<std::vector<int>> ans;
        // node, remaining_sum, path that led to this node
        std::stack<std::tuple<TreeNode *, int, std::vector<int>>> st;
        st.push({root, targetSum - root->val, {root->val}});

        while (!st.empty())
        {
            auto [curr, remaining, path] = st.top();
            st.pop();
            if (!curr->left && !curr->right)
            {
                if (remaining == 0)
                {
                    ans.push_back(path);
                }
                continue;
            }

            if (curr->right)
            {
                auto rPath = path;
                rPath.push_back(curr->right->val);
                st.push({curr->right, remaining - curr->right->val, rPath});
            }
            if (curr->left)
            {
                auto lPath = path;
                lPath.push_back(curr->left->val);
                st.push({curr->left, remaining - curr->left->val, lPath});
            }
        }
        return ans;
    }
};