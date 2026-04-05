#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <utility>
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
  std::vector<int> TopViewOfBinaryTree(TreeNode *root) {
    std::vector<int> ans;
    if (!root) {
      return ans;
    }
    int depth = 0;
    // Col ,node_val
    std::map<int, int> mp;
    std::queue<std::pair<TreeNode *, int>> q;
    // TreeNode*, col
    q.push({root, 0});
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        int col = q.front().second;
        TreeNode *node = q.front().first;
        q.pop();
        // If this col if being visited for the first time.
        // Find takes O(LogN)
        if (mp.find(col) == mp.end()) {
          mp[col] = node->val;
        }
        if (node->left) {
          q.push({node->left, col - 1});
        }
        if (node->right) {
          q.push({node->right, col + 1});
        }
      }
      depth++;
    }

    for (auto it : mp) {
      ans.push_back(it.second);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  TreeNode *node1 = new TreeNode(40);
  TreeNode *node2 = new TreeNode(60);
  TreeNode *node3 = new TreeNode(90);
  TreeNode *node4 = new TreeNode(100);
  TreeNode *node5 = new TreeNode(20, node1, node2);
  TreeNode *node6 = new TreeNode(30, node3, node4);
  TreeNode *node7 = new TreeNode(10, node5, node6);
  std::vector<int> ans = sol.TopViewOfBinaryTree(node7);

  for (auto it : ans) {
    std::cout << it << " ";
  }
  std::cout << "\n";
  return 0;
  // The above code has a time complexity of O(NLogN).
}