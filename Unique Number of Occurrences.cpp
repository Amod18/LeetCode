#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/unique-number-of-occurrences/

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> ump;
        set<int> st;

        for (int i = 0; i < arr.size(); i++)
        {
            ump[arr[i]]++;
        }

        for (auto it : ump)
        {
            if (st.count(it.second))
            {
                return false;
            }
            else
            {
                st.insert(it.second);
            }
        }
        return true;
    }
};

// OR

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> ump;
        set<int> st;

        for (auto it : arr)
        {
            ump[it]++;
        }

        for (auto i : ump)
        {
            st.insert(i.second);
        }

        // If size of map and set are same it means that frequency is unique
        return ump.size() == st.size();
    }
};