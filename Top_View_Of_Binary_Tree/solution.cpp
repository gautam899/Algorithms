#include <iostream>
#include <limits.h>
#include <queue>
#include <set>
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

using T = std::tuple<int, int, int>;

class Solution {
public:
  std::vector<int> TopViewOfBinaryTree(TreeNode *root) {
    std::vector<int> ans;
    if (!root) {
      return ans;
    }
    int depth = 0;
    std::queue<std::pair<TreeNode *, int>> q;
    std::multiset<T> ms;
    // TreeNode*, col
    q.push({root, 0});
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        int col = q.front().second;
        TreeNode *node = q.front().first;
        q.pop();
        ms.insert({col, depth, node->val});
        if (node->left) {
          q.push({node->left, col - 1});
        }
        if (node->right) {
          q.push({node->right, col + 1});
        }
      }
      depth++;
    }
    int prev = INT_MIN;
    for (auto it : ms) {
      int col = std::get<0>(it);
      int depth = std::get<1>(it);
      int node_val = std::get<2>(it);
      if (col != prev) {
        // Visiting this col for the first time.
        ans.push_back(node_val);
        prev = col;
      }
      // If we have already visited this col before skip, we only want to first
      // element of the col.
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

  // The above code is overkill. We are storing more than we need. BFS already
  // guarantees top first visit.
}