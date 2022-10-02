#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

class Solution
{
public:
    const int MOD = 1e9 + 7;

    int waysCount(int n, int k, int target, vector<vector<int>> &dp)
    {
        long long int ans = 0;

        if (target < 0)
        {
            return 0;
        }

        if (n == 0)
        {
            if (target == 0)
            {
                return 1;
            }
            return 0;
        }

        if (dp[n][target] != -1)
        {
            return dp[n][target];
        }

        for (int i = 1; i <= k; i++)
        {
            ans += waysCount(n - 1, k, target - i, dp) % MOD;
        }

        return dp[n][target] = ans % MOD;
    }

    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return waysCount(n, k, target, dp);
    }
};