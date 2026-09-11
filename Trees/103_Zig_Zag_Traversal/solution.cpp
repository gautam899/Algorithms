#include <algorithm>
#include <iostream>
#include <new>
#include <queue>
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
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    std::vector<std::vector<int>> ans;
    if (!root)
      return ans;
    std::queue<TreeNode *> q;
    int direction = 0;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      //   std::cout << size << "\n";
      std::vector<int> curr;
      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();
        curr.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      if (direction == 1)
        std::reverse(curr.begin(), curr.end());
      ans.push_back(curr);
      direction = (direction == 0) ? 1 : 0;
    }
    return ans;
  }
};
int main() {
  Solution sol;
  TreeNode *node1 = new TreeNode(15);
  TreeNode *node2 = new TreeNode(7);
  TreeNode *node3 = new TreeNode(20, node1, node2);
  TreeNode *node4 = new TreeNode(9);
  TreeNode *node5 = new TreeNode(3, node4, node3);
  std::vector<std::vector<int>> ans = sol.zigzagLevelOrder(node5);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      std::cout << ans[i][j] << " ";
    }
    std::cout << "\n";
  }
  return 0;
}