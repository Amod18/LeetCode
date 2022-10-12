#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/largest-perimeter-triangle/

class Solution
{
public:
    int largestPerimeter(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        for (int i = arr.size() - 1; i >= 2; i--)
        {
            if (arr[i] < arr[i - 1] + arr[i - 2])
            {
                return (arr[i] + arr[i - 1] + arr[i - 2]);
            }
        }

        return 0;
    }
};