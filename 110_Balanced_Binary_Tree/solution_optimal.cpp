#include <algorithm>
#include <cstdlib>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {};
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {};
};

class Solution {
public:
  int helper(TreeNode *root) {
    if (!root)
      return 0;
    int ld = helper(root->left);
    int rd = helper(root->right);
    if (ld == -1 || rd == -1)
      return -1;
    if (abs(ld - rd) > 1)
      return -1;

    return 1 + std::max(ld, rd);
  }
  bool isBalanced(TreeNode *root) {
    if (!root)
      return true;
    int val = helper(root);
    return val != -1;
  }
};

int main() {
  TreeNode *node3 = new TreeNode(3);
  TreeNode *node4 = new TreeNode(5);
  TreeNode *node2 = new TreeNode(2, nullptr, node4);
  TreeNode *node1 = new TreeNode(1, node2, node3);
  Solution sol;

  int ans = sol.isBalanced(node1);
  std::cout << ans << "\n";
  return 0;
}