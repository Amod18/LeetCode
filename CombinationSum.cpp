#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/combination-sum

class Solution
{
public:
    void solve(int ind, vector<int> &arr, int target, vector<int> &store, vector<vector<int>> &ans)
    {
        if (ind == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(store);
            }
            return;
        }

        // Calls for picking up the index and reducing the target
        if (arr[ind] <= target)
        {
            store.push_back(arr[ind]);
            solve(ind, arr, target - arr[ind], store, ans);
            store.pop_back();
        }

        // Calls for not picking up the index
        solve(ind + 1, arr, target, store, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        int ind = 0;
        vector<int> store;
        vector<vector<int>> ans;

        solve(ind, candidates, target, store, ans);

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    obj.combinationSum(candidates, target);
}