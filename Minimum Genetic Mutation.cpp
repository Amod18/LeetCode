#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/minimum-genetic-mutation/

class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        unordered_map<string, int> mp, visited;

        vector<char> gene = {'A', 'G', 'T', 'C'};

        for (auto it : bank)
        {
            mp[it]++;
        }

        queue<string> q;
        q.push(start);

        int moves = 0;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                string curr = q.front();
                q.pop();

                if (curr == end)
                    return moves;

                for (int j = 0; j < 8; j++)
                {
                    string temp = curr;

                    for (int k = 0; k < 4; k++)
                    {
                        temp[j] = gene[k];
                        cout << temp << endl;
                        if (mp[temp] && !visited[temp])
                        {
                            q.push(temp);
                            visited[temp]++;
                        }
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};