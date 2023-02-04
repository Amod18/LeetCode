#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/permutation-in-string/description/

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2)
        {
            return false;
        }
        vector<int> vec1(26, 0);
        vector<int> vec2(26, 0);
        for (char ch : s1)
        {
            vec1[ch - 'a']++;
        }
        for (int i = 0; i < n2; i++)
        {
            vec2[s2[i] - 'a']++;
            if (i >= n1)
            {
                vec2[s2[i - n1] - 'a']--;
            }
            if (vec1 == vec2)
            {
                return true;
            }
        }
        return false;
    }
};