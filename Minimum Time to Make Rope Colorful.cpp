#include <bits/stdc++.h>
using namespace std;

// Problem Link : https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        long long ans = 0;
        for (int i = 1; i < colors.size(); ++i)
        {
            int j = i - 1;
            while (i < colors.size() && colors[i] == colors[j])
            {
                ans += min(neededTime[i], neededTime[j]);
                if (neededTime[i] > neededTime[j])
                    j = i;
                i++;
            }
        }
        return ans;
    }
};