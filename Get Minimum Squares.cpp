#include <bits/stdc++.h>
using namespace std;

// Problem link : https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1

class Solution
{
public:
    // 	int solve(int n)
    // 	{
    // 	    int ans = n;

    // 	    if(n == 0)
    // 	    {
    // 	        return 0;
    // 	    }

    // 	    for(int i = 1; i*i <= n; i++)
    // 	    {
    // 	        ans = min(ans, 1 + solve(n - i*i));
    // 	    }

    // 	    return ans;
    // 	}

    int solve(int n, vector<int> &dp)
    {
        int ans = n;

        if (n == 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }

        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + solve((n - i * i), dp));
        }

        dp[n] = ans;
        return dp[n];
    }

    int MinSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
