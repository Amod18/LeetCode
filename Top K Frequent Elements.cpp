#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/top-k-frequent-elements/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        vector<int> res;
        priority_queue<pair<int, int>> pq;

        for (int num : nums)
        {
            map[num]++;
        }

        for (auto it = map.begin(); it != map.end(); it++)
        {
            pq.push(make_pair(it->second, it->first));

            if (pq.size() > (int)map.size() - k)
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};