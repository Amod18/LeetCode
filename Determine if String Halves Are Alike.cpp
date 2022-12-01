#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int size = s.size();
        set<char> check = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt1 = 0;
        int cnt2 = 0;

        for (int i = 0; i < size / 2; i++)
        {
            if (check.count(s[i]))
            {
                cnt1++;
            }
        }
        for (int i = size / 2; i < size; i++)
        {
            if (check.count(s[i]))
            {
                cnt2++;
            }
        }

        return cnt1 == cnt2;
    }
};