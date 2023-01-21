#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/restore-ip-addresses/

class Solution
{
public:
    bool valid(string temp)
    {
        if (temp.size() > 3 || temp.size() == 0)
        {
            return false;
        }

        if (temp.size() > 1 && temp[0] == '0')
        {
            return false;
        }

        if (temp.size() && stoi(temp) > 255)
        {
            return false;
        }

        return true;
    }

    void solve(vector<string> &ans, string output, int ind, string s, int dots)
    {
        if (dots == 3)
        {
            if (valid(s.substr(ind)))
            {
                ans.push_back(output + s.substr(ind));
            }
            return;
        }
        for (int i = ind; i < s.size(); i++)
        {
            if (valid(s.substr(ind, i - ind + 1)))
            {
                output.push_back(s[i]);
                output.push_back('.');
                solve(ans, output, i + 1, s, dots + 1);
                output.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        string res;
        solve(ans, res, 0, s, 0);
        return ans;
    }
};