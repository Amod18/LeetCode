#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/buddy-strings/

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        int x = s.compare(goal);
        if (s.length() != goal.length())
        {
            return false;
        }
        // cout << "AAA";
        if (x == 0)
        {
            // cout << "A";
            set<char> st;
            for (auto i : s)
            {
                st.insert(i);
            }
            if (st.size() <= s.length() - 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        else
        {
            int cnt = 0;
            string a = "";
            string b = "";

            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] != goal[i])
                {
                    a = a + s[i];
                    b = b + goal[i];
                    cnt++;
                }
            }
            if (cnt != 2)
            {
                return false;
            }
            else
            {
                if (a[0] == b[1] && a[1] == b[0])
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
};