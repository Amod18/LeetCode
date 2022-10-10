#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/break-a-palindrome/

class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        int n = palindrome.size();

        for (int i = 0; i < n / 2; ++i)
        {
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';
        return n < 2 ? "" : palindrome;
    }
};