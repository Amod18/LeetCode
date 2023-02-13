#include <bits/stdc++.h>
using namespace std;

// Problem link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/0

class Solution
{
public:
    bool dfs(int start, int vis[], int path[], vector<int> adj[])
    {
        vis[start] = 1;
        path[start] = 1;

        for (auto it : adj[start])
        {
            if (!vis[it])
            {
                if (dfs(it, vis, path, adj))
                {
                    return true;
                }
            }

            else if (path[it])
            {
                return true;
            }
        }

        path[start] = 0;

        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        int path[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, path, adj) == true)
                {
                    return true;
                }
            }
        }

        return false;
    }
};
