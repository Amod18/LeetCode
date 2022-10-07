#include <bits/stdc++.h>
using namespace std;

// Problem link : https://leetcode.com/problems/my-calendar-i/

class MyCalendar
{
public:
    map<int, int> bookings;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto it = bookings.upper_bound(start);
        // it->first = just after the start
        // it->second = just before the end
        if (it == bookings.end() || it->second >= end)
        {
            bookings[end] = start;
            return true;
        }
        else
        {
            return false;
        }
    }
};