#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/find-players-with-zero-or-one-losses/

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_set<int> noLoss, oneLoss, moreLoss;
        vector<vector<int>> ans(2, vector<int>());

        for (auto &match : matches)
        {
            int winner = match[0], loser = match[1];

            if ((oneLoss.find(winner) == oneLoss.end()) && (moreLoss.find(winner) == moreLoss.end()))
            {
                noLoss.insert(winner);
            }

            if (noLoss.find(loser) != noLoss.end())
            {
                noLoss.erase(loser);
                oneLoss.insert(loser);
            }
            else if (oneLoss.find(loser) != oneLoss.end())
            {
                oneLoss.erase(loser);
                moreLoss.insert(loser);
            }
            else if (moreLoss.find(loser) != moreLoss.end())
            {
                continue;
            }
            else
            {
                oneLoss.insert(loser);
            }
        }

        ans[0].assign(noLoss.begin(), noLoss.end());
        ans[1].assign(oneLoss.begin(), oneLoss.end());

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};