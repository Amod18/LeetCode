#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/word-search-ii/

class Solution
{
public:
    // TrieNode
    struct node
    {
        char c;
        int end;
        string word;
        node *child[26];
    };

    struct node *getNode(char c) // get newnode
    {
        node *newnode = new node;
        newnode->c = c;
        newnode->end = 0;
        newnode->word = "";

        for (int i = 0; i < 26; ++i)
        {
            newnode->child[i] = NULL;
        }

        return newnode;
    }
    node *root = getNode('/'); // Root

    // Trie INSERT
    void insert(string s)
    {
        node *curr = root;
        int index, i = 0;
        while (s[i])
        {
            index = s[i] - 'a';
            if (curr->child[index] == NULL)
            {
                curr->child[index] = getNode(s[i]);
            }

            curr = curr->child[index];
            i += 1;
        }
        curr->end += 1;
        curr->word = s;
    }

    void solve(vector<vector<char>> &board, int i, int j, int row, int col, vector<string> &ans, node *curr)
    {
        // Base case --> Doesn't have that char or cell is visited
        int index = board[i][j] - 'a';
        if (board[i][j] == '*' || curr->child[index] == NULL)
        {
            return;
        }

        curr = curr->child[index];
        if (curr->end > 0)
        {
            ans.emplace_back(curr->word);
            curr->end -= 1;
        }

        char ch = board[i][j];
        board[i][j] = '*';

        // Moving top
        if (i > 0)
        {
            solve(board, i - 1, j, row, col, ans, curr);
        }
        // Moving down
        if (i < row - 1)
        {
            solve(board, i + 1, j, row, col, ans, curr);
        }
        // Moving top
        if (j > 0)
        {
            solve(board, i, j - 1, row, col, ans, curr);
        }
        // Moving top
        if (j < col - 1)
        {
            solve(board, i, j + 1, row, col, ans, curr);
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> ans;
        int row = board.size();
        int col = board[0].size();

        // Inserting all the words in TRIE
        for (int i = 0; i < words.size(); ++i)
        {
            insert(words[i]);
        }

        // Now search words

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
                solve(board, i, j, row, col, ans, root);
        }
        return ans;
    }
};