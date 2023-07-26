#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/

class Solution
{
    bool canReachInTime(vector<int> &dist, double hour, int speed)
    {
        double timeReq = 0;
        for (int i = 0; i < dist.size() - 1; ++i)
        {
            timeReq += ((dist[i] + speed - 1) / speed);
        }

        timeReq += ((double)dist.back()) / speed;
        return timeReq <= hour;
    }

public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int N = dist.size();
        if (hour <= (double)(N - 1))
        {
            return -1;
        }

        int start = 1, end = 1e7, mid;
        while (start < end)
        {
            mid = (start + end) / 2;
            if (canReachInTime(dist, hour, mid))
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return end;
    }
};