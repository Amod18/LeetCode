#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/percentage-of-letter-in-string/description/

class Solution
{
public:
    int percentageLetter(string s, char letter)
    {
        int cnt = 0;
        int size = s.size();

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == letter)
            {
                cnt++;
            }
        }
        cout << cnt << " ";
        return floor((cnt * 100) / size);
    }
};