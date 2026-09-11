#include <iostream>
#include <unordered_map>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {};
};
class Solution
{
public:
    TreeNode *helper(std::vector<int> &postorder, int ps, int pe, std::vector<int> &inorder, int is, int ie, std::unordered_map<int, int> &mp)
    {
        // ps -> preorder starting index
        // pe -> preorder ending index
        // is -> inorder starting index
        // ie -> inorder ending index
        if (ps < pe || is > ie)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[ps]);
        // cout<<"val: "<<root->val<<"\n";
        // cout<<"ps "<<ps<<"\n";
        // cout<<"pe "<<pe<<"\n";
        // cout<<"is "<<is<<"\n";
        // cout<<"ie "<<ie<<"\n";
        int ind_root = mp[postorder[ps]];
        int nums_left = ind_root - is;
        int nums_right = ie - ind_root;
        // cout<<"ind_root " << ind_root<<"\n";
        // cout<<"nums_left " << nums_left<<"\n";
        // cout<<"nums_right " << nums_right<<"\n";

        // To iterate only the left side nodes of the current root, we need to ignore the right side of the nodes.
        // This will lead us to trim down our search space to starting from the first left element.
        // ps-nums_right-1, and ending at 0. For inorder it's straight forward, we start at the already starting position and
        // end it at ind_root-1 because that will be the last node for the left subtree.
        root->left = helper(postorder, ps - nums_right - 1, 0, inorder, is,
                            ind_root - 1, mp);
        // To iterate the right side of the current root, we know from how the postorder traversal(left,right,root) works the right
        // right subtree root will be just one index less than the index of the current root and that will
        // end where? remove all the left nodes i.e. pe+nums_left.
        root->right = helper(postorder, ps - 1, pe + nums_left, inorder,
                             ind_root + 1, ie, mp);
        return root;
    }
    TreeNode *formTree(std::vector<int> &postorder, std::vector<int> &inorder)
    {
        // Using preorder we will decide the root and using inorder we will decide the left and right child.
        // Every time we look for the position of root in the inorder vector, we will have to iterate the inorder vector.
        // But instead of doing that, we create a mapping.
        std::unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        TreeNode *root = helper(postorder, postorder.size() - 1, 0, inorder, 0,
                                inorder.size() - 1, mp);
        return root;
    }
};
void printInorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    printInorder(root->left);
    printInorder(root->right);
    std::cout << root->val << " ";
}
int main()
{
    std::vector<int> postorder = {9, 15, 7, 20, 3};
    std::vector<int> inorder = {9, 3, 15, 20, 7};
    Solution sol;
    TreeNode *root = sol.formTree(postorder, inorder);
    printInorder(root);
    return 0;
}