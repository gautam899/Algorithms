#include <iostream>
#include <vector>

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
    std::vector<TreeNode *> helper(int start, int end)
    {
        if (start > end)
            return {nullptr};

        std::vector<TreeNode *> res;
        // We need to choose every element from start to end as a root
        for (int root = start; root <= end; root++)
        {
            // Two possible subproblems.
            std::vector<TreeNode *> leftTree = helper(start, root - 1); // Will contain all possible tree with roots in range start->root-1
            std::vector<TreeNode *> rightTree = helper(root + 1, end);  // Will contain all possible tree with roots in range root+1->end

            for (TreeNode *leftRoot : leftTree) // For every left Root, choose all the right roots as right
            {
                for (TreeNode *rightRoot : rightTree)
                {
                    TreeNode *treeRoot = new TreeNode(root, leftRoot, rightRoot);
                    res.push_back(treeRoot);
                }
            }
        }
        return res;
    }
    std::vector<TreeNode *> generateTrees(int n)
    {
        return helper(1, n);
    }
};

int main()
{
    return 0;
}