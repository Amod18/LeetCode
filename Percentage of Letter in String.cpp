#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(vector<int> adj[], int i, int par, string &s, int &maxAns)
    {
        int node = 1;
        int tempAns = 1;
        for (auto &x : adj[i])
        {
            if (par == x)
                continue;
            int temp = dfs(adj, x, i, s, maxAns);
            if (s[i] == s[x])
                temp = 0;
            temp++;
            tempAns = max(tempAns, node + temp - 1);
            node = max(node, temp);
        }
        maxAns = max(maxAns, tempAns);
        return node;
    }

    int longestPath(vector<int> &parent, string s)
    {
        int n = parent.size();
        if (n == 1)
            return 1;

        vector<int> adj[n];
        for (int i = 1; i < n; i++)
        {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        int maxAns = 0;
        dfs(adj, 0, -1, s, maxAns);
        return maxAns;
    }
};