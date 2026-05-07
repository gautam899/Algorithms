#include <iostream>
#include <stack>

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

class Operations
{
    /* Floor in a BST is the greatest value, less than or equal to x.
       Basically, inorder predecessor. To find the Floor of the key, we can perform a inorder traversal of
       the tree while keeping track of the inorder predecessor.
    */
public:
    TreeNode *_floor_bst(TreeNode *root, int key)
    {
        /*
        if (!root)
            return nullptr;
        std::stack<TreeNode *> st;
        TreeNode *ans = nullptr;
        while (root || !st.empty())
        {
            while (root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (root->val <= key)
                ans = root;
            root = root->right;
        }
        return nullptr; // Not found
        // Above approach is O(N). Complete inorder traversal.
        */

        // Optimal. We can use the property of BST
        TreeNode *ans;
        while (root)
        {
            if (root->val <= key)
            {
                ans = root;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return ans;
        // In the above optimal approach, we are not performing a complete inorder traversal but rather travelling
        // either right or left. Hence, the time complexity of the above approach is O(H).
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

    Operations op;
    TreeNode *root = node1;
    TreeNode *ans = op._floor_bst(node1, 1);
    (ans) ? std::cout << "Floor: " << ans->val : std::cout << "Not Found\n";
    return 0;
}