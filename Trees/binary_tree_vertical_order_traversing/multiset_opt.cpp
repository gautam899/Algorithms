
#include <iostream>
#include <limits.h>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), right(nullptr), left(nullptr) {};
  TreeNode(int val) : val(val), right(nullptr), left(nullptr) {};
  TreeNode(int val, TreeNode *left, TreeNode *right)
      : val(val), left(left), right(right) {};
};

using T = std::tuple<int, int, int>; // use a tuple in multiset instead of using
                                     // a comparator.

class Solution {
public:
  std::vector<std::vector<int>> verticalOrderTraversal(TreeNode *root) {
    std::vector<std::vector<int>> ans;
    if (!root) {
      return ans;
    }
    // Col, depth, node.
    std::multiset<T> ms;

    int depth = 0; // Depth/level
    int col = 0;
    // Node, col
    std::queue<std::pair<TreeNode *, int>> q;
    q.push({root, col});

    while (!q.empty()) {
      int size = q.size();

      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front().first; // O(1) operation
        int c = q.front().second;
        q.pop();
        ms.insert({c, depth, node->val}); // O(log n) operation
        if (node->left) {
          q.push({node->left, c - 1});
        }
        if (node->right) {
          q.push({node->right, c + 1});
        }
      }
      depth++; // Increase the depth.
    }
    // Total bfs cost-> O(NlogN)

    // std::cout << ms.size();
    std::vector<int> curr;
    int prev = INT_MIN;
    for (auto it : ms) {
      int col = std::get<0>(it);
      int val = std::get<2>(it);
      if (col != prev) {
        if (!curr.empty()) {
          ans.push_back(curr);
        }
        curr.clear();
        prev = col;
      }
      // If its same a prev col
      curr.push_back(val);
    }
    // O(N) for iterating the multiset.

    ans.push_back(curr); // The last column remains
    return ans;
  }
};

int main() {
  Solution sol;
  TreeNode *node1 = new TreeNode(15);
  TreeNode *node2 = new TreeNode(7);
  TreeNode *node3 = new TreeNode(9);
  TreeNode *node4 = new TreeNode(20, node1, node2);
  TreeNode *node5 = new TreeNode(3, node3, node4);

  std::vector<std::vector<int>> ans = sol.verticalOrderTraversal(node5);

  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      std::cout << ans[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}

// Time complexity O(NlogN).