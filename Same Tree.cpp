#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/same-tree/description/

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
    vector<int> helper(TreeNode *p, vector<int> &p1)
    {
        p1.push_back(p->val);
        if (p->left != nullptr)
        {
            helper(p->left, p1);
        }
        else
        {
            p1.push_back(0);
        }

        if (p->right != nullptr)
        {
            helper(p->right, p1);
        }
        else
        {
            p1.push_back(0);
        }

        return p1;
    }

    vector<int> helper1(TreeNode *q, vector<int> &q1)
    {
        q1.push_back(q->val);
        if (q->left != nullptr)
        {
            helper(q->left, q1);
        }
        else
        {
            q1.push_back(0);
        }

        if (q->right != nullptr)
        {
            helper(q->right, q1);
        }
        else
        {
            q1.push_back(0);
        }

        return q1;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if (p == NULL && q != NULL)
        {
            return false;
        }
        if (p != NULL && q == NULL)
        {
            return false;
        }

        vector<int> p1;
        vector<int> q1;

        helper(p, p1);
        helper1(q, q1);

        for (auto it : p1)
        {
            cout << it << " ";
        }
        cout << '\n';
        for (auto it : q1)
        {
            cout << it << " ";
        }
        return p1 == q1 ? true : false;
    }
};