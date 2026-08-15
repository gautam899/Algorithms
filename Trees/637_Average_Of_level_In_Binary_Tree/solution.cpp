#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
    std::vector<double> averageOfLevels(TreeNode *root)
    {
        std::vector<double> ans;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            double sum = 0.0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                sum += (double)node->val;
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            double av = sum / size;
            ans.push_back(av);
        }
        return ans;
        // T.C: O(N) We visit all the nodes once
        // S.C: O(W) where w is maximum width of the Binary Tree. In a complete binary tree that would be O(N/2)
    }
};

int main()
{
}