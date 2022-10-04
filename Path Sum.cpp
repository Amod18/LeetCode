#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/path-sum/

class Solution
{
public:
    bool hasPathSum(Treenode *root, int targetSum)
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