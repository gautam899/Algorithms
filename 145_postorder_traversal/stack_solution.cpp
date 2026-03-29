#include<iostream>
#include<vector>
#include<stack>

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
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        if(!root) {
            return {};
        }
        TreeNode* curr = root;
        std::stack<TreeNode*> s1;
        std::stack<TreeNode*> s2;
        s1.push(curr);
        while(!s1.empty()) {
            curr = s1.top();
            s1.pop();
            s2.push(curr);
            if(curr->left) s1.push(curr->left);
            if(curr->right) s1.push(curr->right);
        }

        while(!s2.empty()) {
            curr = s2.top();
            s2.pop();
            ans.push_back(curr->val);
        }
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