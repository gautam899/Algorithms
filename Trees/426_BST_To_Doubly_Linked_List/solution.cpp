#include <iostream>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode *next = nullptr;
    TreeNode *prev = nullptr;

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
    TreeNode *prev;
    TreeNode *head; // We need these two pointers to keep track of the inorder predecessor and the new head
    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);

        if (prev)
        {
            // Prev's right pointer will point to the curr node and the curr node's left pointer will point
            // to prev
            prev->right = root;
            root->left = prev;
        }
        else
        {
            head = root; // First node in the inorder traversal is the new head.
        }

        prev = root;

        inorder(root->right);
    }
    TreeNode *convert_BST_To_DLL(TreeNode *root)
    {
        if (!root)
            return nullptr;
        prev = nullptr;
        head = nullptr;

        inorder(root);

        // At this moment the prev will be pointing to the last node.
        prev->right = head;
        head->left = prev;
        return head;
    }
};