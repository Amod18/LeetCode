#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/

class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        // Aim is to replace the max char with the min char!

        int n = s1.size();
        char ch[26];

        for (int i = 0; i < 26; i++)
        {
            ch[i] = 'a' + i;
        }

        for (int i = 0; i < n; i++)
        {
            char tempChar = max(ch[s1[i] - 'a'], ch[s2[i] - 'a']);

            char replacedChar = min(ch[s1[i] - 'a'], ch[s2[i] - 'a']);

            for (int i = 0; i < 26; i++)
            {

                if (ch[i] == tempChar)
                {
                    ch[i] = replacedChar;
                }
            }
        }

        for (int i = 0; i < baseStr.size(); i++)
        {

            baseStr[i] = ch[baseStr[i] - 'a'];
        }

        return baseStr;
    }
};