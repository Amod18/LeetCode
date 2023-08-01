#include <bits/stdc++.h>
using namespace std;

// Problem Link : https://leetcode.com/problems/combinations/

class Solution
{
private:
    void solve(int start, int n, vector<int> &temp, vector<vector<int>> &ans, int k)
    {
        if (temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            temp.push_back(i);
            solve(i + 1, n, temp, ans, k);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> store;

        solve(1, n, store, ans, k);

        return ans;
    }
};