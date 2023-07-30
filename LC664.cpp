#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strangePrinter(string s)
    {
        vector<vector<int>> dpVec(s.size() + 1, vector<int>(s.size() + 1));
        for (int len = 0; len < s.size(); ++len)
        {
            for (int start = 0; start < s.size() - len; ++start)
            {
                int end = start + len;
                dpVec[start][end] = len + 1;
                for (int k = start + 1; k <= end; ++k)
                {
                    int steps = dpVec[start][k - 1] + dpVec[k][end] - (s[k - 1] == s[end] ? 1 : 0);
                    dpVec[start][end] = min(dpVec[start][end], steps);
                }
            }
        }
        return dpVec[0][s.size() - 1];
    }
};

int main()
{
    Solution obj;
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;

        cout << obj.strangePrinter(s) << endl;
    }
}