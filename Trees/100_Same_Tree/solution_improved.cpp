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
  bool helper(TreeNode *a, TreeNode *b) {
    if (!a && !b)
      return true;
    if (!a || !b)
      return false;

    if (a->val == b->val && helper(a->left, b->left) &&
        helper(a->right, b->right))
      return true;
    return false;
  }
  bool isSameTree(TreeNode *p, TreeNode *q) { return helper(p, q); }
};

int main() {
  Solution sol;
  TreeNode *node1 = new TreeNode(2);
  TreeNode *node2 = new TreeNode(3);
  TreeNode *node3 = new TreeNode(1, node1, node2);

  TreeNode *node4 = new TreeNode(2);
  TreeNode *node5 = new TreeNode(3);
  TreeNode *node6 = new TreeNode(1, node4, node5);

  int ans = sol.isSameTree(node3, node6);
  std::cout << ans << "\n";
  return 0;
}