#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/image-overlap/

class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        vector<int> vec1, vec2;
        int N = img1.size();
        int ans = 0;
        unordered_map<int, int> ump;

        for (int i = 0; i < N * N; ++i)
        {
            if (img1[i / N][i % N] == 1)
            {
                vec1.push_back(i / N * 100 + i % N);
            }
        }

        for (int i = 0; i < N * N; ++i)
        {
            if (img2[i / N][i % N] == 1)
            {
                vec2.push_back(i / N * 100 + i % N);
            }
        }

        for (int i : vec1)
        {
            for (int j : vec2)
            {
                ump[i - j]++;
            }
        }

        for (auto it : ump)
        {
            ans = max(ans, it.second);
        }

        return ans;
    }
};