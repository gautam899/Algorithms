#include <iostream>
#include <stack>
#include <unordered_map>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    // Constructor for root node
    TreeNode(int val = 0, TreeNode *parent = nullptr) : val(val), parent(parent) {};
    // Constructor for the non-root node.
    TreeNode(int val, TreeNode *left, TreeNode *right, TreeNode *parent) : val(val), left(left), right(right), parent(parent) {};
};

class Solution
{
public:
    bool helper(TreeNode *root, int k, std::unordered_map<int, int> &mp)
    {
        if (!root)
            return false;
        if (mp.find(k - root->val) != mp.end())
            return true;
        mp[root->val]++;
        return helper(root->left, k, mp) || helper(root->right, k, mp);
    }
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        std::unordered_map<int, int> mp;
        return helper(root, k, mp);
    }
};

int main()
{
    TreeNode *node1 = new TreeNode(8, nullptr);
    TreeNode *node2 = new TreeNode(3, nullptr, nullptr, node1);
    TreeNode *node3 = new TreeNode(10, nullptr, nullptr, node1);
    TreeNode *node4 = new TreeNode(1, nullptr, nullptr, node2);
    TreeNode *node5 = new TreeNode(6, nullptr, nullptr, node2);
    TreeNode *node6 = new TreeNode(14, nullptr, nullptr, node3);
    TreeNode *node7 = new TreeNode(4, nullptr, nullptr, node5);
    TreeNode *node8 = new TreeNode(7, nullptr, nullptr, node5);
    TreeNode *node9 = new TreeNode(13, nullptr, nullptr, node6);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node5->left = node7;
    node5->right = node8;
    node3->right = node6;
    node6->left = node9;

    Solution op;
    TreeNode *root = node1;
    bool ans = op.findTarget(root, 9);
    // (ans) ? std::cout << "Ceil: " << ans->val : std::cout << "Not Found\n";
    return 0;
}