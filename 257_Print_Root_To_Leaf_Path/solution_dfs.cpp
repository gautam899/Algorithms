#include<iostream>
#include<string>
#include<vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {};

};

class Solution {
public:
    void helper(TreeNode* root, std::vector<std::string> &ans, std::string s) {
        if(!root) return;

        // If a leaf node.
        if(!root->left && !root->right) {
            s += std::to_string(root->val);
            ans.push_back(s);
            return;
        }

        s += std::to_string(root->val);
        // Left
        helper(root->left, ans, s + "->");
        // Right
        helper(root->right, ans, s + "->");
    }

    std::vector<std::string> printPath(TreeNode* root) {
        std::vector<std::string> ans;
        if(!root) return ans;
        helper(root, ans, "");
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
    
    for(auto it: ans) {
        std::cout<<it<<" ";
    }
    std::cout<<"\n";
    return 0;
    /*
        Time complexity is O(N) as we will be visiting all the nodes. 
        The issue is, in every recurcive call, we are creating a new copy of string. It would be better if can be done 
        with one string.
    */ 
}