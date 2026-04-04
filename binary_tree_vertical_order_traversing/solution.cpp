
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
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

class Compare1 {
public:
  bool operator()(std::pair<int, std::vector<std::pair<int, TreeNode *>>> &a,
                  std::pair<int, std::vector<std::pair<int, TreeNode *>>> &b) {
    return a.first >
           b.first; // If comp(a,b) is true then a has heigher priority.
  }
};

struct Compare2 {
  bool operator()(std::pair<int, TreeNode *> &a,
                  std::pair<int, TreeNode *> &b) {
    // Return true if a should come before b
    if (a.first < b.first) {
      return true;
    } else if (a.first == b.first) {
      return a.second->val < b.second->val;
    }
    return false;
  }
};

class Solution {
public:
  void dfs(TreeNode *root,
           std::unordered_map<int, std::vector<std::pair<int, TreeNode *>>> &mp,
           int offset, int depth) {
    if (!root)
      return;

    mp[offset].push_back({depth, root});
    dfs(root->left, mp, offset - 1, depth + 1);
    dfs(root->right, mp, offset + 1, depth + 1);
  }

  std::vector<std::vector<int>> verticalOrderTraversal(TreeNode *root) {
    std::vector<std::vector<int>> ans;
    if (!root) {
      return ans;
    }
    // offset, <depth, node>
    std::unordered_map<int, std::vector<std::pair<int, TreeNode *>>> mp;
    dfs(root, mp, 0, 0);

    std::cout << mp.size() << "\n";
    // Now we have our unordered map storing the offset mapped with depth and
    // node but in a out of order fashion
    std::priority_queue<
        std::pair<int, std::vector<std::pair<int, TreeNode *>>>,
        std::vector<std::pair<int, std::vector<std::pair<int, TreeNode *>>>>,
        Compare1>
        pq;
    for (auto it : mp) {
      std::cout << "Pushing offset " << it.first << "\n";
      pq.push({it.first, it.second});
    }
    // std::cout << pq.size() << "\n";

    int mini_offset =
        pq.top().first; // Minimum offset. Will help us evaluate index.
    std::cout << "mini" << mini_offset << "\n";

    // While is giving seg fault
    while (!pq.empty()) {
      std::pair<int, std::vector<std::pair<int, TreeNode *>>> a = pq.top();
      pq.pop();
      int offset = a.first;
      std::vector<std::pair<int, TreeNode *>> v = a.second;
      /* If there are more than one node in a row inside a specific
        column, the value should be sorted from smaller to large. i.e for
        a col c, and depth d, if there are more than one nodes at depth
        d, they must be sorted.
      */
      std::sort(v.begin(), v.end(), Compare2()); // The columns by their depth.

      /* If for the same column we wish to sort by depth.*/
      // std::sort(v.begin(), v.end()); // The columns by their depth.
      int index = offset - mini_offset;
      std::cout << "Index: " << index << "\n";
      if (ans.size() <= index) {
        ans.push_back({});
      }
      for (int i = 0; i < v.size(); i++) {
        ans[index].push_back(v[i].second->val);
      }
    }
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