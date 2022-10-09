#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    unordered_set<int> sumCheck;
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
        {
            return false;
        }

        if (sumCheck.count(k - root->val))
        {
            return true;
        }

        sumCheck.insert(root->val);

        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};