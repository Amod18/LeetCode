#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/flip-string-to-monotone-increasing/

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int ans = 0;
        int cntOne = 0;
        for (auto x : s)
        {
            if (x == '1')
            {
                cntOne++;
            }
            else
            {
                ans++;
                ans = min(ans, cntOne);
            }
        }
        return ans;
    }
};