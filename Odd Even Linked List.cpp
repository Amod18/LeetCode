#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/odd-even-linked-list/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenhead = head->next;

        while (even != NULL and even->next != NULL)
        {
            // Odd
            odd->next = odd->next->next;
            odd = odd->next;
            // Even
            even->next = even->next->next;
            even = even->next;
        }

        odd->next = evenhead;
        return head;
    }
};