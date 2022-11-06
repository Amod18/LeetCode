#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/orderly-queue/

class Solution
{
public:
    string orderlyQueue(string S, int K)
    {
        // If k > 1 then by applying substr method will result into bubble sort so to reduce the time                   complexity we can directly use the sort function
        if (K > 1)
        {
            sort(S.begin(), S.end());
            return S;
        }

        string res = S;

        for (int i = 1; i < S.length(); i++)

        {
            res = min(res, S.substr(i) + S.substr(0, i));
        }

        return res;
    }
};