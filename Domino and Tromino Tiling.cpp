#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/domino-and-tromino-tiling/description/

class Solution
{
public:
    int numTilings(int n)
    {
        vector<int> ans = {0, 1, 2, 5};
        const int M = 1e9 + 7;

        if (n <= 3)
        {
            return ans[n];
        }

        for (int i = 4; i <= n; i++)
        {
            int temp = (2 * (ans[i - 1] % M) % M + ans[i - 3] % M) % M;
            ans.push_back(temp);
        }

        return ans[n];
    }
};