#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

class Solution
{
public:
    int getTravelTime(int root, int parent, vector<vector<int>> &array, vector<bool> &hasApple, int n)
    {
        int travelTime = 0;

        for (auto child : array[root])
        {
            if (child != parent)
            {
                int temp = getTravelTime(child, root, array, hasApple, n);

                if (temp > 0 || hasApple[child])
                {
                    travelTime += temp + 2;
                }
            }
        }

        return travelTime;
    }

    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> array(n);

        for (auto e : edges)
        {
            array[e[0]].push_back(e[1]);
            array[e[1]].push_back(e[0]);
        }

        return getTravelTime(0, 0, array, hasApple, n);
    }
};