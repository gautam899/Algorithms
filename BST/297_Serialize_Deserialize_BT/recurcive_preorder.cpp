#include <iostream>
#include <queue>
#include <string>
#include <sstream> // getline comes from here.
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {};
};
/*
           1
       /      \
    2           3
  /   \      /    \
n       n   4       5
          /   \   /   \
         n    n  n     n
*/

class Solution
{
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root)
    {
        std::ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data)
    {
        std::istringstream in(data);
        return deserialize(in);
    }

    // The implementation of the serialize and deserialize function is something we keep private
private:
    void serialize(TreeNode *root, std::ostringstream &out)
    {
        if (root)
        {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else
        {
            out << "# ";
        }
    }
    // After serializing the above tree, we get, "1 2 # # 3 4 # # 5 # # "
    /*
        Deserialize:
        start with val = "1"
        root = 1
            root->left
                root = 2
                    root->left # return nullptr
                    root->right # return nullptr
            root->right
                root = 3
                    root->left
                        root = 4
                            root->left = # return nullptr
                            root->right = # return nullptr
                    root->right
                        root = 5
                            root->left = # return nullptr
                            root->right = # return nullptr
        return root // 1
    */

    TreeNode *deserialize(std::istringstream &in)
    {
        std::string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode *root = new TreeNode(std::stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

void __printInorder(TreeNode *root)
{
    std::stack<TreeNode *> st;
    while (root || !st.empty())
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();
        std::cout << root->val << " ";
        root = root->right;
    }
    std::cout << "\n";
}
int main()
{
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(4, node1, node2);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(6);
    TreeNode *node6 = new TreeNode(5, node4, node5);
    TreeNode *node7 = new TreeNode(2);
    TreeNode *node8 = new TreeNode(3, node7, node6);
    TreeNode *node9 = new TreeNode(1, node3, node8);
    TreeNode *root = node9;

    Solution ser, deser;
    __printInorder(root);
    TreeNode *ans = deser.deserialize(ser.serialize(root));
    __printInorder(ans); // Should be same as the prev.
    // The Time complexity is O(N) since we are visiting every node once.
    // The space complexity of this approach is O(H) for balanced tree and O(N) in worst case.
    return 0;
}