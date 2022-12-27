#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/

class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        vector<int> diff;
        int ans = 0;

        for (int i = 0; i < capacity.size(); i++)
        {
            int dif = capacity[i] - rocks[i];
            diff.emplace_back(dif);
        }

        sort(diff.begin(), diff.end());

        for (int i = 0; i < diff.size(); i++)
        {
            if (diff[i] == 0)
            {
                ans++;
            }
            else
            {
                if (diff[i] - additionalRocks <= 0)
                {
                    ans++;
                    additionalRocks -= diff[i];
                }
                else
                {
                    break;
                }
            }
        }

        return ans;
    }
};