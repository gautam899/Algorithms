#include<iostream>
#include<vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void helper(TreeNode* curr, std::vector<int>& ans){
        if(!curr) return;

        ans.push_back(curr->val);
        helper(curr->left, ans);
        helper(curr->right, ans);
    }
    std::vector<int> preorderTraversal(TreeNode* root) {
        // Root, left, right.
        std::vector<int> ans;
        TreeNode* curr = root;
        helper(curr, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    std::vector<int> ans = sol.preorderTraversal(node1);
    for(auto it:ans){
        std::cout<<it<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
