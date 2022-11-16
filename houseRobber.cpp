#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/house-robber

class Solution
{
private:
    int maximumSum(int ind, vector<int> &arr)
    {
        int prev = arr[0];
        int prev2 = 0;

        for (int i = 1; i < arr.size(); i++)
        {
            int pickCall = arr[i];
            if (i > 1)
            {
                pickCall += prev2;
            }
            int notPickCall = prev;

            int curr = max(pickCall, notPickCall);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

public:
    int rob(vector<int> &nums)
    {
        return maximumSum(nums.size() - 1, nums);
    }
};

int main()
{
    vector<int> arr = {2, 7, 9, 3, 1};

    Solution obj;

    cout << obj.rob(arr) << endl;
}