#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/visit-array-positions-to-maximize-score/description/

class Solution
{
    vector<vector<long>> dp;

public:
    long maxScore(vector<int> &nums, int x)
    {
        long answer = nums[0];
        dp = vector<vector<long>>(nums.size(), vector<long>(2, -1));

        if (answer % 2 == 0)
        {
            answer += giveanswer(nums, 1, 0, x);
        }
        else
        {
            answer += giveanswer(nums, 1, 1, x);
        }

        return answer;
    }

    long giveanswer(vector<int> &nums, int index, int parity, int x)
    {
        if (index == nums.size())
        {
            return 0;
        }

        if (dp[index][parity] != -1)
        {
            return dp[index][parity];
        }

        long take = 0;
        long ntake = 0;

        if (parity == 0 && nums[index] % 2 == 0)
        {
            take = nums[index] + giveanswer(nums, index + 1, 0, x);
        }

        if (parity == 0 && nums[index] % 2 != 0)
        {
            take = nums[index] - x + giveanswer(nums, index + 1, 1, x);
        }

        if (parity == 1 && nums[index] % 2 != 0)
        {
            take = nums[index] + giveanswer(nums, index + 1, 1, x);
        }

        if (parity == 1 && nums[index] % 2 == 0)
        {
            take = nums[index] - x + giveanswer(nums, index + 1, 0, x);
        }

        ntake = giveanswer(nums, index + 1, parity, x);

        return dp[index][parity] = max(take, ntake);
    }
};