#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/

/*
Approach :
    1) Find the difference between the capacity and the rocks already in it.
    2) Sort the difference array
    3) Then check if the difference is zero then the max capacity has been reached and that
        will be added to our ans and if not then we will check that can the difference be zero
        or not with the available rocks or not.
*/

class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int ans = 0;

        for (int i = 0; i < capacity.size(); i++)
        {
            int dif = capacity[i] - rocks[i];
            capacity[i] = dif;
        }

        sort(capacity.begin(), capacity.end());

        for (int i = 0; i < capacity.size(); i++)
        {
            if (capacity[i] == 0)
            {
                // if zero == max capacity already reached
                ans++;
            }
            else
            {
                if (capacity[i] - additionalRocks <= 0)
                {
                    ans++;
                    additionalRocks -= capacity[i];
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