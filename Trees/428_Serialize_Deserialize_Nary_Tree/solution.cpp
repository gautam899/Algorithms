#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <stack>

class Node
{
public:
    int val;
    std::vector<Node *> children;

    Node()
    {
        val = 0;
    }

    Node(int _val)
    {
        val = _val;
        children = std::vector<Node *>();
    }

    Node(int _val, std::vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    std::string serialize(Node *root)
    {
        std::ostringstream out;
        serialize(root, out);
        return out.str();
    }

    Node *deserialize(std::string data)
    {
        std::istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(Node *root, std::ostringstream &out)
    {
        std::queue<Node *> q;
        q.push(root);
        out << root->val << ' ';

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            int size = node->children.size();
            out << size << ' ';
            for (Node *it : node->children)
            {
                q.push(it);
                out << it->val << ' ';
            }
        }
    }

    Node *deserialize(std::istringstream &in)
    {
        std::queue<Node *> q;
        std::string val;
        in >> val;
        Node *root = new Node(std::stoi(val));
        q.push(root);

        while (!q.empty())
        {
            if (!in)
                break;
            Node *node = q.front();
            q.pop();
            in >> val; // Size of node's children vector
            int size = std::stoi(val);
            for (int i = 0; i < size; i++)
            {
                in >> val;
                int child_val = std::stoi(val);
                Node *child = new Node(child_val);
                q.push(child);
                node->children.push_back(child);
            }
        }
        return root;
    }
};

void preorder(Node *root)
{
    if (!root)
        return;
    std::vector<int> ans;
    std::stack<Node *> st;
    Node *curr = root;
    st.push(curr);
    while (!st.empty())
    {
        curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        for (auto it = curr->children.rbegin(); it != curr->children.rend();
             it++)
        {
            st.push(*it);
        }
    }

    std::cout << "Printing Preorder: " << std::endl;
    for (const auto &it : ans)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return;
}
int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(3);
    Node *node3 = new Node(2);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *root = node1;
    node1->children.push_back(node2);
    node1->children.push_back(node3);
    node1->children.push_back(node4);
    node2->children.push_back(node5);
    node2->children.push_back(node6);
    Solution sol;

    std::string d = sol.serialize(root);
    // std::cout << d << std::endl;
    preorder(root);
    Node *new_root = sol.deserialize(d);
    preorder(new_root);
    return 0;
}