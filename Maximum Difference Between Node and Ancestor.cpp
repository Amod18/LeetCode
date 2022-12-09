#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // preorder traversal
    int maxAncestorDiff(TreeNode *root, int maxi = INT_MIN, int mini = INT_MAX)
    {

        if (nullptr == root)
        {
            return 0;
        }

        // root
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        maxiV = max(maxiV, abs(maxi - mini));

        maxAncestorDiff(root->left, maxi, mini);  // left child
        maxAncestorDiff(root->right, maxi, mini); // Right child

        return maxiV;
    }

private:
    int maxiV = 0;
};