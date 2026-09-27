#include <iostream>
#include <string>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode()
    {
        val = 0;
    }

    TreeNode(int _val)
    {
        val = _val;
    }

    TreeNode(int _val, TreeNode *_left, TreeNode *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
public:
    TreeNode *buildTree(const std::string &s)
    {
        if (s.size() == 0)
            return nullptr;
        std::size_t firstParenthesis = s.find('(');

        if (firstParenthesis == std::string::npos)
        {
            return new TreeNode(std::stoi(s));
        }

        // Root value is everything before the first parenthesis
        int rootValue = stoi(s.substr(0, firstParenthesis));
        TreeNode *root = new TreeNode(rootValue);

        int parenthesisCount = 0;
        int startPosition = firstParenthesis;

        // Start iterating to left starting from the start position
        for (size_t i = startPosition; i < s.size(); i++)
        {
            if (s[i] == '(')
                ++parenthesisCount;
            else if (s[i] == ')')
                --parenthesisCount;

            // When the parenthesis are balance we have found a complete subtree
            if (parenthesisCount == 0)
            {
                // First balanced group is the left subtree
                if (startPosition == firstParenthesis)
                {
                    root->left = buildTree(s.substr(startPosition + 1, i - startPosition - 1));

                    // Update the start position
                    startPosition = i + 1;
                }
                else if (startPosition != firstParenthesis) // The second balance grp is the right subtree
                {
                    root->right = buildTree(s.substr(startPosition + 1, i - startPosition - 1));
                }
            }
        }
        return root;
    }
};

void printInorder(TreeNode *root)
{
    if (!root)
        return;

    printInorder(root->left);
    std::cout << root->val << " " << std::endl;
    printInorder(root->right);
}
int main()
{
    std::string s = "4(2(3)(1))(6(5))";
    Solution sol;
    TreeNode *root = sol.buildTree(s);
    printInorder(root);
    return 0;

    // Time Complexity of the above approach is O(N) and the Space complexity is O(N).
}