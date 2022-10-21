#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/contains-duplicate-ii/

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.count(nums[i]))
            {
                int diff = abs(map[nums[i]] - i);
                if (diff <= k)
                {
                    return true;
                }
                else
                {
                    map[nums[i]] = i;
                }
            }
            map.insert({nums[i], i});
        }
        return false;
    }
};