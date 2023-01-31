#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/best-team-with-no-conflicts/

class Solution
{
public:
    int bestTeamScore(vector<int> &s, vector<int> &a)
    {
        int ans = 0;
        int n = s.size();
        vector<vector<int>> store;
        int dp[n];
        memset(dp, 0, sizeof dp);

        for (int i = 0; i < n; i++)
        {
            store.push_back({-a[i], -s[i]});
        }
        sort(store.begin(), store.end());

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (-store[i][1] <= -store[j][1])
                {
                    dp[i] = max(dp[i], dp[j] - store[i][1]);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};