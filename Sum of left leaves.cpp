#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/sum-of-left-leaves

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
    void solve(TreeNode *root, int &res, int fac)
    {
        if (root != NULL)
        {
            if (root->left == NULL && root->right == NULL)
            {
                res += root->val * fac;
            }
            solve(root->left, res, 1);
            solve(root->right, res, 0);
        }
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        int res = 0;
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return res;
        }

        solve(root, res, 1);
        return res;
    }
};