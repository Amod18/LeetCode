#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/group-anagrams/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        if (strs.size() == 1)
        {
            return {{strs[0]}};
        }

        vector<vector<string>> ans;
        map<string, vector<string>> mpp;

        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mpp[strs[i]].push_back(str);
        }

        for (auto i = mpp.begin(); i != mpp.end(); i++)
        {
            ans.emplace_back(i->second);
        }

        return ans;
    }
};