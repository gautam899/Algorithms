#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    TreeNode *helper(ListNode *start, ListNode *end)
    {
        if (start == end)
            return nullptr;
        // Find the mid
        ListNode *slow = start;
        ListNode *fast = start;
        while (fast != end && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Slow is at mid
        TreeNode *root = new TreeNode(slow->val);

        root->left = helper(start, slow);

        root->right = helper(slow->next, end);

        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *start = head;
        ListNode *end = nullptr;
        return helper(start, end);
    }
};