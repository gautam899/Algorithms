#include <vector>
#include <iostream>
#include <stack>
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node()
    {
        val = 0l;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val)
    {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
public:
    std::vector<int> inorderTraversal(Node *root)
    {
        if (!root)
            return {};
        std::vector<int> ans;
        Node *temp = root;
        std::stack<Node *> st;
        while (temp || !st.empty())
        {
            // Keep moving to the left
            while (temp)
            {
                st.push(temp);
                temp = temp->left;
            }
            // No left child remaining.
            temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            temp = temp->right;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    node1->right = node2;
    node2->left = node3;
    Node *root = node1;
    std::vector<int> ans = sol.inorderTraversal(root);
    for (auto it : ans)
    {
        std::cout << it << std::endl;
    }
    return 0;
}
