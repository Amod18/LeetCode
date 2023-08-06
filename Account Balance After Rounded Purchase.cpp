#include <bits/stdc++.h>
using namespace std;

// Problem Link : https://leetcode.com/contest/biweekly-contest-110/problems/account-balance-after-rounded-purchase/

class Solution
{
public:
    int accountBalanceAfterPurchase(int purchaseAmount)
    {
        int rem = purchaseAmount / 10;

        if (purchaseAmount % 10 >= 5)
        {
            return 100 - (rem + 1) * 10;
        }
        return 100 - rem * 10;
    }
};