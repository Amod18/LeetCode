#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/reverse-words-in-a-string/

class Solution
{
public:
    string reverseWords(string s)
    {
        string result;
        int i = 0, n = s.length();

        while (i < n)
        {
            // To detect spaces
            while (i < n && s[i] == ' ')
            {
                i++;
            }
            if (i >= n)
            {
                break;
            }

            int j = i;

            // To detect characters
            while (j < n && s[j] != ' ')
            {
                j++;
            }

            // To take out the words from the string
            string sub = s.substr(i, j - i);

            if (result.length() == 0)
            {
                result = sub;
            }

            else
            {
                result = sub + " " + result;
            }

            i = j + 1;
        }
        return result;
    }
};