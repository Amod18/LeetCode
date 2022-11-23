#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/valid-sudoku/

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int blocks[3][3][9] = {0};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }

                int num = board[i][j] - '1';

                if (cols[num][j]++ || rows[i][num]++ || blocks[i / 3][j / 3][num]++)
                {
                    return false;
                }
            }
        }
        return true;
    }
};