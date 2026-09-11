#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {};
  TreeNode(int val) : val(0), left(nullptr), right(nullptr) {};
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {};
};

class Solution {
public:
  TreeNode *helper(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || p == root || q == root) {
      return root;
    }

    TreeNode *left = helper(root->left, p, q);
    TreeNode *right = helper(root->right, p, q);

    if (!left)
      return right;
    else if (!right)
      return left;
    else
      return root; // If both left and right are not null then the current node
                   // is the LCA.
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return helper(root, p, q);
  }
};

int main() {
  Solution sol;
  TreeNode *node1 = new TreeNode(7);
  TreeNode *node2 = new TreeNode(4);
  TreeNode *node3 = new TreeNode(2, node1, node2);
  TreeNode *node4 = new TreeNode(6);
  TreeNode *node5 = new TreeNode(5, node4, node3);
  TreeNode *node6 = new TreeNode(0);
  TreeNode *node7 = new TreeNode(8);
  TreeNode *node8 = new TreeNode(1, node6, node7);
  TreeNode *node9 = new TreeNode(3, node5, node8);

  TreeNode *ans = sol.lowestCommonAncestor(node9, node5, node8);
  std::cout << ans->val << "\n";
  return 0;
}