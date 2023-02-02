#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/verifying-an-alien-dictionary/description/

class Solution
{
public:
    bool isAlienSorted(vector<string> words, string order)
    {
        int mapArr[26];
        for (int i = 0; i < 26; i++)
        {
            mapArr[order[i] - 'a'] = i;
        }

        for (string &w : words)
        {
            for (char &c : w)
            {
                c = mapArr[c - 'a'];
            }
        }
        
        return is_sorted(words.begin(), words.end());
    }
};