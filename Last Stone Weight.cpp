#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/last-stone-weight/description/

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        int ans = 0;
        priority_queue<int> pq;

        for (auto it : stones)
        {
            pq.push(it);
        }

        while (true)
        {
            if (pq.size() == 1 || pq.size() == 0)
            {
                break;
            }

            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();

            if (top1 == top2)
            {
                continue;
            }
            else
            {
                pq.push(top1 - top2);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};