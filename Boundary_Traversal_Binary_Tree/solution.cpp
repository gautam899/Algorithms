#include <algorithm>
#include <iostream>
#include <vector>

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
  void helper(TreeNode *root, std::vector<int> &v, int mode) {
    if (!root)
      return;
    if (mode == 0) {
      // Left Boundary
      // If not a leaf node.
      if (root->left != root->right) {
        v.push_back(root->val);
        if (root->left) {
          helper(root->left, v, mode);
        } else {
          helper(root->right, v, mode);
        }
      }

    } else if (mode == 1) {
      // Leaves. Gather the leaves from left to right.
      if (root->left == root->right) {
        v.push_back(root->val);
      } else {
        helper(root->left, v, mode);
        helper(root->right, v, mode);
      }

    } else {
      // Right
      if (root->left != root->right) {
        v.push_back(root->val);
        if (root->right) {
          helper(root->right, v, mode);
        } else {
          helper(root->left, v, mode);
        }
      }
    }
  }
  std::vector<int> boundary_traversal(TreeNode *root) {
    std::vector<int> ans;
    std::vector<int> left_b;
    std::vector<int> right_b;
    std::vector<int> leaves;
    ans.push_back(root->val); // Start with the root
    // Left boundary
    if (root->left)
      helper(root->left, left_b, 0);
    helper(root, leaves, 1); // Leaves
    if (root->right)
      helper(root->right, right_b, 2); // Right boundary

    std::reverse(right_b.begin(), right_b.end());
    leaves.reserve(leaves.size() + right_b.size());
    leaves.insert(leaves.end(), right_b.begin(), right_b.end());
    left_b.reserve(left_b.size() + leaves.size());
    left_b.insert(left_b.end(), leaves.begin(), leaves.end());
    ans.reserve(ans.size() + left_b.size());
    ans.insert(ans.end(), left_b.begin(), left_b.end());
    return ans;
  }
};
int main() {
  //   TreeNode *node1 = new TreeNode(4);
  //   TreeNode *node2 = new TreeNode(8);
  //   TreeNode *node3 = new TreeNode(9);
  //   TreeNode *node4 = new TreeNode(6);
  //   TreeNode *node5 = new TreeNode(7);
  //   TreeNode *node6 = new TreeNode(5, node2, node3);
  //   TreeNode *node7 = new TreeNode(2, node1, node6);
  //   TreeNode *node8 = new TreeNode(3, node4, node5);
  //   TreeNode *node9 = new TreeNode(1, node7, node8);
  //   TreeNode *root = node9;
  TreeNode *node1 = new TreeNode(4);
  TreeNode *node2 = new TreeNode(3, nullptr, node1);
  TreeNode *node3 = new TreeNode(2, nullptr, node2);
  TreeNode *node4 = new TreeNode(1, nullptr, node3);

  TreeNode *root = node4;

  Solution sol;
  std::vector<int> ans = sol.boundary_traversal(root);
  //   std::cout << ans.size();
  for (auto it : ans) {
    std::cout << it << " ";
  }
  std::cout << "\n";
  return 0;
}