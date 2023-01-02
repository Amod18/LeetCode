#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/detect-capital/description/

class Solution
{
public:
    bool detectCapitalUse(string s)
    {
        if (s[0] >= 'A' && s[0] <= 'Z')
        {
            int count = 0;
            for (char c : s)
            {
                if (c >= 'A' && c <= 'Z')
                {
                    count++;
                }
            }

            if (count == 1)
                return true;

            return count == s.size();
        }

        else
        {
            for (char c : s)
            {
                if (c >= 'A' && c <= 'Z')
                {
                    return false;
                }
            }
        }
        return true;
    }
};