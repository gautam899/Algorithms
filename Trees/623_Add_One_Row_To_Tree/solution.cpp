#include <queue>

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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            root = node;
            return root;
        }

        int level = 1;
        std::queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty() && level < depth - 1)
        {
            int size = queue.size();
            for (std::size_t i = 0; i < size; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            level++;
        }

        // iterate the level
        while (!queue.empty())
        {
            TreeNode *leftNewNode = new TreeNode(val);
            TreeNode *rightNewNode = new TreeNode(val);
            TreeNode *node = queue.front();
            queue.pop();
            // Rewire the left of node.
            leftNewNode->left = node->left;
            node->left = leftNewNode;
            // Rewire the right of the node
            rightNewNode->right = node->right;
            node->right = rightNewNode;
        }
        return root;
    }
};

int main()
{
    /** TODO: Implement the tree. **/
    /* Time Complexity of the approach is O(N) at the worst case. */
    return 0;
}