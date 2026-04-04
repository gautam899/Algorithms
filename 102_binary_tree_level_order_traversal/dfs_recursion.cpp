#include<iostream>
#include<queue>
#include<vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    // Constructors
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {};
};

class Solution {
public:
    void helper(TreeNode* root, std::vector<std::vector<int>>& ans, int level) {
        if(!root) return;

        // If the size of ans if less that or equal to the level number, push another vector.
        if(ans.size() <= level) {
            ans.push_back({});
        }
        ans[level].push_back(root->val); // Push the node on the current level index.
        helper(root->left, ans, level+1);
        helper(root->right, ans, level+1);
    }
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        if(!root) return ans;
        helper(root, ans, 0);
        return ans;
    }
};

int main() {
    Solution sol;
    TreeNode* node1 = new TreeNode(15);
    TreeNode* node2 = new TreeNode(7);
    TreeNode* node3 = new TreeNode(9);
    TreeNode* node4 = new TreeNode(20, node1, node2);
    TreeNode* node5 = new TreeNode(3, node3, node4);

    std::vector<std::vector<int>> ans = sol.levelOrder(node5);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            std::cout<<ans[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
