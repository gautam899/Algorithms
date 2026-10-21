#include <iostream>

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(){val=0;}
	TreeNode(int _val) {val=_val;}
	TreeNode(int _val, TreeNode *_left, TreeNode *_right) {val=_val;left=_left;right=_right;}
};

class Solution {
public:
    bool dfs(TreeNode* root) {
        if (!root)
            return false;

        bool left = dfs(root->left);
        bool right = dfs(root->right);

        if (root->left && !left)
            root->left = nullptr;

        if (root->right && !right)
            root->right = nullptr;

        // We return true if either of left or right is true or the root value
        // is 1.
        return left || right || root->val == 1;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(dfs(root)) return root;
        return nullptr;
    }
};

int main() {
	// TODO: Create a binary tree and call the function.
}
