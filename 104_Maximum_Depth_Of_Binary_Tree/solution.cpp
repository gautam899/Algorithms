#include <iostream>
#include <string>
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
  void helper(TreeNode *root, std::vector<std::string> &ans,
              std::string &path) {
    if (!root)
      return;

    int len = path.size();

    path += std::to_string(root->val);

    // If a leaf node.
    if (!root->left && !root->right) {
      ans.push_back(path);
      // Backtrack before return
      path.resize(len);
      return;
    } else {
      path += "->";
      // Left
      helper(root->left, ans, path);
      // Right
      helper(root->right, ans, path);
    }

    path.resize(len); // Backtrack
  }

  std::vector<std::string> printPath(TreeNode *root) {
    std::vector<std::string> ans;
    if (!root)
      return ans;
    std::string path = "";
    helper(root, ans, path);
    return ans;
  }
};

int main() {
  TreeNode *node3 = new TreeNode(3);
  TreeNode *node4 = new TreeNode(5);
  TreeNode *node2 = new TreeNode(2, nullptr, node4);
  TreeNode *node1 = new TreeNode(1, node2, node3);
  Solution sol;

  std::vector<std::string> ans = sol.printPath(node1);

  for (auto it : ans) {
    std::cout << it << " ";
  }
  std::cout << "\n";
  return 0;
  /*
      Time complexity is O(N) as we will be visiting all the nodes.
  */
}