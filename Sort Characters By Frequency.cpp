#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/sort-characters-by-frequency/

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> ump;
        priority_queue<pair<int, char>> store; // maxheap according to frequency of characters
        string ans;

        for (char c : s)
        {
            ump[c]++;
        }

        for (auto it : ump)
        {
            store.push({it.second, it.first});
        }

        while (!store.empty())
        {
            ans += string(store.top().first, store.top().second); // frequency times the character
            store.pop();
        }

        return ans;
    }
};