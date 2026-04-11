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
    // The intution behind this approach is to consider the fact that if parent
    // is n then the left child is 2*n and right child is 2*n + 1.
    long long ans = 0;
    if (!root)
      return ans;
    std::queue<std::pair<TreeNode *, long long>> q;
    q.push({root, 1}); // We can push any value a the index of parent here as
                       // only care about the difference.
    while (!q.empty()) {
      int size = q.size();
      ans = std::max(ans, q.back().second - q.front().second + 1);
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front().first;
        int index = q.front().second;
        q.pop();
        if (node->left)
          q.push({node->left, 2 * index});
        if (node->right)
          q.push({node->right, 2 * index + 1});
      }
    }
    return ans;
  }
};

int main() {
  TreeNode *node1 = new TreeNode(5);
  TreeNode *node2 = new TreeNode(3);
  TreeNode *node3 = new TreeNode(9);
  TreeNode *node4 = new TreeNode(3, node1, node2);
  TreeNode *node5 = new TreeNode(2, nullptr, node3);
  TreeNode *node6 = new TreeNode(1, node4, node5);

  Solution sol;
  long long ans = sol.maxWidth(node6);
  std::cout << ans << "\n";
  return 0;
}
