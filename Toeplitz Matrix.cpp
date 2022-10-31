#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/toeplitz-matrix/

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        bool ans = true;
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            int temp = matrix[0][i];
            int col = i;
            int row = 0;

            while (row < n && col < m)
            {
                if (temp != matrix[row][col])
                {
                    return false;
                }

                col++;
                row++;
            }
        }

        for (int i = 1; i < n; i++)
        {
            int temp = matrix[i][0];
            int row = i;
            int col = 0;

            while (row < n && col < m)
            {
                if (temp != matrix[row][col])
                {
                    return false;
                }

                row++;
                col++;
            }
        }

        return ans;
    }
};