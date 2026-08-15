#include <vector>
#include <iostream>

/*
    On way to find the mode of the binary Tree is to perform a DFS search while keeping a unordered_map
    keeping track of the freq of the nodes. While performing the DFS we can keep track of max freq found so far.
    Once done we can push all the nodes with freq equal to the maxFreq in a vector.

    But can we do it in a way without using extra space i.e without using unordered_map. Yes.
    Inorder Traversal. Inordered Traversal in a BST is sorted traversal and because of this property
    the similar elements can be traversed together. We need to keep track curr freq, MaxF
*/

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
    int maxFreq = 0;
    int freq = 0;
    int val = 0;
    void helper(TreeNode *root, std::vector<int> &ans)
    {
        if (!root)
            return;
        helper(root->left, ans);
        if (val == root->val)
        {
            freq++;
        }
        else
        {
            freq = 1;
            val = root->val;
        }

        if (freq > maxFreq)
        {
            ans = {root->val};
            maxFreq = freq;
        }
        else if (freq == maxFreq)
        {
            ans.push_back(root->val);
        }
        helper(root->right, ans);
    }

    std::vector<int> findMode(TreeNode *root)
    {
        if (!root)
            return {};
        std::vector<int> ans;
        helper(root, ans);
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
    std::vector<int> ans = sol.findMode(node1);
    for (auto it : ans)
    {
        std::cout << it << std::endl;
    }
    return 0;
}