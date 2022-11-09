#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/online-stock-span/

class StockSpanner
{
public:
    stack<pair<int, int>> st; // maintaing stack of pair(prices, days <= price)

    int next(int price)
    {
        int ans = 1;

        while (!st.empty() && st.top().first <= price)
        {
            ans += st.top().second;
            st.pop();
        }

        st.push({price, ans});
        return ans;
    }
};