#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> r;
        for (int i = 0; i < piles.size(); i++)
        {
            r.push(piles[i]);
        }
        for (int i = 0; i < piles.size(); i++)
            while (k > 0)
            {
                int le = r.top();
                r.pop();
                le = le - le / 2;
                r.push(le);
                k--;
            }
        int sum = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            sum = sum + r.top();
            r.pop();
        }
        return sum;
    }
};