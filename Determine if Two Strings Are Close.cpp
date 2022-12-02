#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/determine-if-two-strings-are-close/

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        // Idea is to check the that both the strings contains same letters and the same amount of frequency of each letter.

        vector<int> w1(26, 0), w2(26, 0);
        set<char> str1, str2;

        for (char c : word1)
        {
            w1[c - 'a']++;
            str1.insert(c);
        }
        for (char c : word2)
        {
            w2[c - 'a']++;
            str2.insert(c);
        }

        sort(begin(w1), end(w1));
        sort(begin(w2), end(w2));

        return w1 == w2 && str1 == str2;
    }
};