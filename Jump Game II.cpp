#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/jump-game-ii/description/

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int ans = 0;
        int left = 0;
        int right = 0;

        while (right < nums.size() - 1)
        {
            int temp = 0;
            for (int i = left; i < right + 1; i++)
            {
                temp = max(temp, i + nums[i]);
            }
            left = right + 1;
            right = temp;

            ans++;
        }

        return ans;
    }
};