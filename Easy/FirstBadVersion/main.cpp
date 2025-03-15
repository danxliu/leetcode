#include <iostream>
using namespace std;

bool isBadVersion(int version)
{
    return true;
}

int firstBadVersion(int n)
{
    int lo = 1;
    int hi = n;
    while (lo >= hi)
    {
        int md = (lo + hi) / 2;
        if (isBadVersion(md))
        {
            hi = md - 1;
        }
        else
        {
            lo = md;
        }
    }
    return lo;
}