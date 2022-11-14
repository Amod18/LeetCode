#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class Solution
{
public:
    void dfs(vector<vector<int>> &stones, int index, vector<bool> &visited, int &n)
    {
        visited[index] = true;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1]))
            {
                dfs(stones, i, visited, n);
            }
        }
    }

    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<bool> visited(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            dfs(stones, i, visited, n);
            cnt++;
        }
        return n - cnt;
    }
};