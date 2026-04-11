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
  bool ans = true;
  int helper(TreeNode *root) {
    if (!root)
      return 0;
    int ld = helper(root->left);
    int rd = helper(root->right);
    ans = ans &&
          (abs(ld - rd) <=
           1); // Even if single subtree does not meet the criteria. Its false.

    return 1 + std::max(ld, rd);
  }

  bool isBalanced(TreeNode *root) {
    if (!root)
      return true;
    helper(root);
    return ans;
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