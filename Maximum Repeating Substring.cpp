#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/maximum-repeating-substring/description/

class Solution
{
public:
    int maxRepeating(string s, string w)
    {
        int ans = 0;
        string str = w;

        while (s.find(str) != -1)
        {
            str += w;
            ans++;
        }

        return ans;
    }
};