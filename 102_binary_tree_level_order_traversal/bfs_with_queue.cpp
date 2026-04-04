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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        std::vector<int> level;
        if(!root) return ans;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            // std::cout<<size<<std::endl;
            level.resize(0);
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
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
