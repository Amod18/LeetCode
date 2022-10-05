#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {

        if (root == NULL)
        {
            return root;
        }

        if (depth == 1)
        {
            TreeNode *newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }

        queue<TreeNode *> addNode;
        addNode.push(root);
        addNode.push(NULL);
        int depthCount = 1;

        while (depth - depthCount != 1)
        {
            TreeNode *front = addNode.front();
            addNode.pop();

            if (front == NULL)
            {
                addNode.push(NULL);
                depthCount++;
            }
            else
            {
                if (front->left != NULL)
                    addNode.push(front->left);
                if (front->right != NULL)
                    addNode.push(front->right);
            }
        }

        while (addNode.size() != 0)
        {
            TreeNode *front = addNode.front();
            addNode.pop();

            if (front == NULL)
                continue;

            TreeNode *newNodeLeft = new TreeNode(val);
            TreeNode *newNodeRight = new TreeNode(val);

            newNodeLeft->left = front->left;
            newNodeRight->right = front->right;

            front->left = newNodeLeft;
            front->right = newNodeRight;
        }

        return root;
    }
};