#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/greatest-common-divisor-of-strings/description/

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        int len1 = str1.size(), len2 = str2.size();
        if (len1 == len2)
        {
            if (str1 == str2)
            {
                return str1;
            }
            else
            {
                return "";
            }
        }
        if (len1 > len2)
        {
            if (str1.substr(0, str2.size()) == str2)
            {
                return gcdOfStrings(str1.substr(str2.size()), str2);
            }
            else
            {
                return "";
            }
        }
        else
        {
            return gcdOfStrings(str2, str1);
        }
    }
};