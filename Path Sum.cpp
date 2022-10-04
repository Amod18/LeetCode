#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
        {
            return false;
        }

        targetSum -= root->val;

        if (!root->left && !root->right && targetSum == 0)
        {
            return true;
        }

        return hasPathSum(root->right, targetSum) || hasPathSum(root->left, targetSum);
    }
};