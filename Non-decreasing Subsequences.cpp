#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/non-decreasing-subsequences/

class Solution
{
public:
    set<vector<int>> uniq;
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backtrack(0, nums.size(), nums, {});
        return vector<vector<int>>(uniq.begin(), uniq.end());
    }

    void backtrack(int start, int n, vector<int> &nums, vector<int> comb)
    {
        if (comb.size() > 1)
        {
            uniq.insert(comb);
        }

        for (int i = start; i < n; i++)
        {
            if (comb.size() == 0 || nums[i] >= comb.back())
            {
                comb.push_back(nums[i]);
                backtrack(i + 1, n, nums, comb);
                comb.pop_back();
            }
        }
    }
};