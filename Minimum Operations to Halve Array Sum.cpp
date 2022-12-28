#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/minimum-operations-to-halve-array-sum/description/

class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        int ans = 0;
        priority_queue<long double> pq;

        long double total = 0;
        long double reduce = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            total += nums[i];
        }
        long double target = total / 2;
        while (true)
        {
            long double curr = pq.top();
            pq.pop();
            reduce += curr / 2;
            ans++;
            pq.push(curr / 2);
            if (target >= total - reduce)
            {
                break;
            }
        }

        return ans;
    }
};