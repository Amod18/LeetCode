#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string w1 = "";
        string w2 = "";

        for (int i = 0; i < word1.size(); i++)
        {
            w1 += word1[i];
        }

        for (int i = 0; i < word2.size(); i++)
        {
            w2 += word2[i];
        }

        int a = 0;
        int b = 0;

        while (a < w1.length() || b < w2.length())
        {
            if (w1[a] == w2[b])
            {
                a++;
                b++;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};