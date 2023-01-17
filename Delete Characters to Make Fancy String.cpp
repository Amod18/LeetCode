#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/

class Solution
{
public:
    string makeFancyString(string s)
    {
        int cnt = 1;
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i + 1] == s[i])
            {
                cnt++;
            }

            else
            {
                cnt = 1;
            }

            if (cnt < 3)
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};