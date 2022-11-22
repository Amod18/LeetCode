#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/perfect-squares/

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp{0};

        while (dp.size() <= n)
        {
            int m = dp.size(), sqr = INT_MAX;

            for (int i = 1; i * i <= m; ++i)
            {
                sqr = min(sqr, dp[m - i * i] + 1);
            }

            dp.push_back(sqr);
        }

        return dp[n];
    }
};