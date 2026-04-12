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

TreeNode *ans;
class Solution {
public:
  // Unlike normal LCA we do not return if we found one of the target. We
  // traverse the whole tree to verify if both the targets exist
  bool helper(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
      return false;
    }

    bool left = helper(root->left, p, q);
    bool right = helper(root->right, p, q);

    // If left and right are true, our root is the lca.
    if (left && right) {
      ans = root;
    }

    // If our target lies on either side and the current node is the other
    // target the current node is the lca.
    if ((left || right) && (root == p || root == q))
      ans = root;

    // Return true if the current subtree contains atleast of the target node.
    return (left || right || root == p || root == q);
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    helper(root, p, q);
    return ans;
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

  sol.lowestCommonAncestor(node9, node5, node8);
  std::cout << ans->val << "\n";
  return 0;
}