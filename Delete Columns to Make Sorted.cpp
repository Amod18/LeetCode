#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/delete-columns-to-make-sorted/description/

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int ans = 0;

        for (int i = 0; i <= strs[0].size(); i++)
        {
            string temp = "";
            string temp2 = "";
            for (int j = 0; j < strs.size(); j++)
            {
                cout << strs[j][i];
                temp += strs[j][i];
                temp2 += strs[j][i];
            }

            sort(temp2.begin(), temp2.end());

            if (temp2 != temp)
            {
                ans++;
            }
            cout << '\n';
        }

        return ans;
    }
};