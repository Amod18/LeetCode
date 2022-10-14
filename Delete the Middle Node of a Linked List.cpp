#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == NULL)
        {
            return NULL;
        }

        ListNode *temp = head;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast->next == NULL)
        {
            temp->next = slow->next;
        }
        else
        {
            slow->next = slow->next->next;
        }

        return head;
    }
};