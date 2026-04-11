#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>

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
  int maxWidth(TreeNode *root) {
    if (!root)
      return 0;
    int ans = 1;

    std::queue<TreeNode *> q;
    int level = 0;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      int next_level_w = 0;
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();
        // If neither of the child are null or either of them are null then we
        // increase the with by 2.
        // if ((node->left && !node->right) || (node->right && !node->left) ||
        //     (node->left && node->right)) {
        //   next_level_w += 2;
        // }

        if (node->left && !node->right) {
          next_level_w += 2;
          node->right = new TreeNode(0);
        } else if (!node->left && node->right) {
          next_level_w += 2;
          node->left = new TreeNode(0);
        } else if (node->left && node->right) {
          next_level_w += 2;
        }
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      std::cout << "Curr level width: " << next_level_w << "\n";
      ans = std::max(ans, next_level_w);
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *node1 = new TreeNode(5);
  TreeNode *node2 = new TreeNode(3);
  TreeNode *node3 = new TreeNode(9);
  TreeNode *node4 = new TreeNode(3, node1, node2);
  TreeNode *node5 = new TreeNode(2, nullptr, node3);
  TreeNode *node6 = new TreeNode(1, node4, node5);

  Solution sol;
  int ans = sol.maxWidth(node6);
  std::cout << ans << "\n";
  return 0;
}