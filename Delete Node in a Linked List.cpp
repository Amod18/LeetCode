#include <bits/stdc++.h>
using namespace std;

// Problem Link : https://leetcode.com/problems/delete-node-in-a-linked-list/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *N)
    {
        *N = *N->next;
    }
};