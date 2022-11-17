#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/rectangle-area/

class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int areaOfA = (ay2 - ay1) * (ax2 - ax1);
        int areaOfB = (by2 - by1) * (bx2 - bx1);

        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int overlapX = right - left;

        int top = min(ay2, by2);
        int bottom = max(ay1, by1);
        int overlapY = top - bottom;

        int areaOfOverlap = 0;

        if (overlapX > 0 && overlapY > 0)
        {
            areaOfOverlap = overlapX * overlapY;
        }

        int totalArea = areaOfA + areaOfB - areaOfOverlap;

        return totalArea;
    }
};