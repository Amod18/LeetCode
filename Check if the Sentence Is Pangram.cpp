#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/check-if-the-sentence-is-pangram/

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        set<char> ans;

        if (sentence.size() < 26)
        {
            return false;
        }

        else
        {
            for (int i = 0; i < sentence.size(); i++)
            {
                ans.insert(sentence[i]);
            }
        }

        if (ans.size() == 26)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};