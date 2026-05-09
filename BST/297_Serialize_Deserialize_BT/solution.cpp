#include <iostream>
#include <queue>
#include <string>
#include <sstream> // getline comes from here.
#include <stack>

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
    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root)
    {
        // We can perform a bfs traversal of the tree and store it in form of a string
        std::string s = "";
        if (!root)
            return s;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (!node)
            {
                s.append("#,"); // We use append instead of "+=", as += creates a new string every time and '.append' appends the existing string.
            }
            else
            {
                s.append(std::to_string(node->val) + ',');
            }
            if (node)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data)
    {

        // Use the string to deserialize the data.
        if (data.size() == 0)
            return nullptr;
        std::queue<TreeNode *> q;

        // Convert the string into a stream that we can read
        std::stringstream s(data);
        std::string str;

        // We need a way to read the stream and seperate out the data based upon the delimeter/seperator ','. Inorder to do that we use the CPP function 'getline'. getline read the stream and put that into a string until a delimeter(if present) occurs. This function is defined in header <string>
        std::getline(s, str, ',');

        TreeNode *root = new TreeNode(stoi(str));
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front(); // Now, the next two values seperated by delimeter in the stream will be the left and the right of the node.
            q.pop();

            // Get left
            std::getline(s, str, ',');
            if (str == "#")
            {
                node->left = nullptr;
            }
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Get Right
            std::getline(s, str, ',');
            if (str == "#")
            {
                node->right = nullptr;
            }
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
        /*
         Take for example: string = "1,2,3,#,#,4,5,#,#,#,#,"
         While deserializing, We start with 1 in the queue.
         The left and right for the node 1 are 2 and 3. Push 2 and into the queue
         Next we take 2, left and right for 2 as getline gives are #, # i.e. nullptr.
         Next we take 3 out of the queue, left and right for 3 and 4,5(push)
         For 4 and 5 both, the left and right are nullptr.
        */
    }
};

void __printInorder(TreeNode *root)
{
    std::stack<TreeNode *> st;
    while (root || !st.empty())
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();
        std::cout << root->val << " ";
        root = root->right;
    }
    std::cout << "\n";
}
int main()
{
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(4, node1, node2);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(6);
    TreeNode *node6 = new TreeNode(5, node4, node5);
    TreeNode *node7 = new TreeNode(2);
    TreeNode *node8 = new TreeNode(3, node7, node6);
    TreeNode *node9 = new TreeNode(1, node3, node8);
    TreeNode *root = node9;

    Solution ser, deser;
    __printInorder(root);
    TreeNode *ans = deser.deserialize(ser.serialize(root));
    __printInorder(ans); // Should be same as the prev.
    // The time complexity is O(N) since we are visiting every node once, and space complexity is
    // O(N) since we are storing all the nodes into the queue.
    return 0;
}