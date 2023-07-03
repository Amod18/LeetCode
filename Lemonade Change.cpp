#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/lemonade-change/
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;
        int ten = 0;

        for (auto it : bills)
        {
            if (it == 5)
            {
                five++;
            }
            else if (it == 10)
            {
                if (five == 0)
                {
                    return 0;
                }
                five--;
                ten++;
            }
            else
            {
                if (five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return 0;
                }
            }
        }

        return 1;
    }
};