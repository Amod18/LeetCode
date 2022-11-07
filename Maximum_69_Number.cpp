#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/maximum-69-number/

class Solution
{
public:
    int maximum69Number(int num)
    {
        vector<int> intStore;
        int ans = 0;
        int digit;

        while (num > 0)
        {
            digit = num % 10;
            intStore.emplace_back(digit);
            num /= 10;
        }

        reverse(intStore.begin(), intStore.end());

        for (auto i : intStore)
        {
            cout << i << " ";
        }

        for (int i = 0; i < intStore.size(); i++)
        {
            if (intStore[i] == 6)
            {
                intStore[i] = 9;
                break;
            }
        }
        cout << endl;
        for (auto i : intStore)
        {
            cout << i << " ";
        }

        int i = intStore.size() - 1;
        int place = 1;

        while (i >= 0)
        {
            ans = ans + (intStore[i] * place);
            i--;
            place *= 10;
        }

        return ans;
    }
};