#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int myAtoi(string s)
{
    bool neg = false;
    // Format string
    int i = 0;
    while (s[i] == ' ')
    {
        i++;
    }
    s = s.substr(i);
    i = 0;
    if (s[0] == '-')
    {
        neg = true;
        s = s.substr(1);
    }
    else if (s[0] == '+')
    {
        s = s.substr(1);
    }
    long long ans = 0;
    while (isdigit(s[i]))
    {
        ans *= 10;
        ans += s[i] - '0';
        if (ans > INT_MAX && !neg)
            return INT_MAX;
        if (ans > INT_MAX && neg)
            return INT_MIN;
        i++;
    }
    if (neg)
    {
        ans *= -1;
    }
    if (ans > INT_MAX)
        return INT_MAX;
    if (ans < INT_MIN)
        return INT_MIN;
    return ans;
}

int main()
{
    myAtoi("20000000000000000000");
}