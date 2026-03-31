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
    std::vector<int> preorderTraversal(TreeNode* root) {
        // Morris Pre-order traveral
        if(!root){
            return {};
        }
        std::vector<int> ans;
        TreeNode* curr = root;
        TreeNode* prev;
        while(curr){
            // Printing the curr here will not be the right choice as curr can be visited twice.
            if(!curr->left){
                // Print the curr and move right.
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                prev = curr->left;
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if(!prev->right) {
                    // Curr is being visited the first time.
                    ans.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
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