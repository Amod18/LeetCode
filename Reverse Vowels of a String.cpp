#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution
{
public:
    string reverseVowels(string s)
    {
        int start = 0;
        int end = s.size() - 1;
        set<char> vow({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});

        while (end > start)
        {
            if (vow.count(s[start]) && vow.count(s[end]))
            {
                cout << "hi";
                swap(s[start], s[end]);
                start++;
                end--;
            }

            else if (!vow.count(s[start]) && vow.count(s[end]))
            {
                start++;
            }

            else if (vow.count(s[start]) && !vow.count(s[end]))
            {
                end--;
            }

            else
            {
                start++;
                end--;
            }
        }

        return s;
    }
};

int main()
{
    Solution obj;

    obj.reverseVowels("hello");

    return 0;
}