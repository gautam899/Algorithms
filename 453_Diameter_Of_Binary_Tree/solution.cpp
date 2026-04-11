#include <algorithm>
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
  int ans = 0;
  int helper(TreeNode *root) {
    if (!root)
      return 0;
    int ld = helper(root->left);
    int rd = helper(root->right);

    ans = std::max(ans, ld + rd); // ans should be updated to the sum of left
                                  // and right depth to the leaf node.
    return 1 + std::max(ld, rd);  // Return 1 more that the longest path to the
                                  // left node for the current node.
  }
  int diameterOfBinaryTree(TreeNode *root) {
    if (!root)
      return 0;
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

  int ans = sol.diameterOfBinaryTree(node1);
  std::cout << ans << "\n";
  return 0;
}