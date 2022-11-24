#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/word-search

class Solution
{
public:
    bool DFS(vector<vector<char>> &board, string word, int i, int j, int n)
    {
        if (n == word.size())
        {
            return true;
        }

        // If i and j are out of bound or if the characters aren't equal
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n])
        {
            return false;
        }

        // mark as visited
        board[i][j] = '0';

        bool status = DFS(board, word, i + 1, j, n + 1) || // down
                      DFS(board, word, i, j + 1, n + 1) || // right
                      DFS(board, word, i - 1, j, n + 1) || // up
                      DFS(board, word, i, j - 1, n + 1);   // left

        // change the character back for other searches
        board[i][j] = word[n];

        return status;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        if (word == "")
        {
            return false;
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                // Checking for chars and DFS
                if (board[i][j] == word[0] && DFS(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};