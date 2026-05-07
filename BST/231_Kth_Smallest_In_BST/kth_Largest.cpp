#include <iostream>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    // Constructor for root node.
    TreeNode(int val = 0, TreeNode *parent = nullptr) : val(val), left(nullptr), right(nullptr), parent(parent) {};
    // For non-leaf node.
    TreeNode(int val, TreeNode *left, TreeNode *right, TreeNode *parent) : val(val), left(left), right(right), parent(parent) {};
};

class Operations
{
public:
    // In order to find the kth largest element in the BST, unlike finding the Kth Smallest, we can perform
    // reverse inorder traversal.
    TreeNode *kth_Largest(TreeNode *root, int k)
    {
        std::stack<TreeNode *> st;
        // Iterative inorder traversal.
        while (root || !st.empty())
        {
            while (root)
            {
                st.push(root);
                root = root->right;
            }
            root = st.top();
            st.pop();
            if (--k == 0)
            {
                return root;
            }
            root = root->left;
        }
        return nullptr;
        // Time complexity:
    }
};

int main()
{
    Operations op;

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

    TreeNode *ans = op.kth_Largest(node1, 1);
    std::cout << ans->val << "\n";
    return 0;
    // The time complexity for the above code is O(K). The above code is good approach for a static BST
    // but will be slow if the tree is changed frequently.
    // Follow up: Optimize it in such a way that we can perform a kth smallest search operation efficiently even when the tree changes frequently.
}
