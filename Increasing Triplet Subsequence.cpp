#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int mini1 = INT_MAX;
        int mini2 = INT_MAX;

        for (auto i : nums)
        {
            if (i < mini1)
            {
                mini1 = i;
            }
            else if (mini1 < i && i < mini2)
            {
                mini2 = i;
            }
            else if (mini2 < i)
            {
                return true;
            }
        }
        return false;
    }
};