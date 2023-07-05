#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int ans = 0, left = 0, right = 0, curr = 0;

        while (right < nums.size())
        {
            if (nums[right] == 0)
            {
                curr++;
            }

            while (curr > 1)
            {
                if (nums[left] == 0)
                {
                    curr--;
                }
                left++;
            }
            right++;
            ans = max(ans, right - left - 1);
        }

        return ans;
    }
};