#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/time-based-key-value-store/

class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> ump;
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        ump[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (ump.find(key) == ump.end())
        {
            return "";
        }

        if (ump[key][0].first > timestamp)
        {
            return "";
        }

        // Binary Search
        int l = 0;
        int r = ump[key].size() - 1;
        string ans;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (ump[key][mid].first == timestamp)
            {
                return ump[key][mid].second;
            }
            else if (ump[key][mid].first < timestamp)
            {
                ans = ump[key][mid].second;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return ans;
    }
};