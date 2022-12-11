#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
private:
    int DFS(TreeNode *root, int &maxSum)
    {
        if (!root)
            return 0;
        int left = max(0, DFS(root->left, maxSum));
        int right = max(0, DFS(root->right, maxSum));
        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        DFS(root, maxSum);
        return maxSum;
    }
};