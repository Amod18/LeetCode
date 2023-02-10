#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/as-far-from-land-as-possible/

int delRow[] = {-1, 0, 1, 0};
int delCol[] = {0, 1, 0, -1};

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int dist = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                }
            }
        }

        if (q.size() == n * m)
        {
            return -1;
        }

        while (q.size())
        {
            int size = q.size();
            dist++;
            while (size--)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];
                    if (nRow >= 0 and nRow < n and nCol >= 0 and
                        nCol < m and grid[nRow][nCol] == 0)
                    {
                        q.push({nRow, nCol}), grid[nRow][nCol] = 1;
                    }
                }
            }
        }
        return dist - 1;
    }
};