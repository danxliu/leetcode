#include <iostream>
#include <algorithm>
using namespace std;

string addBinary(string a, string b)
{
    int i = a.size() - 1;
    int j = b.size() - 1;
    int sum = 0;
    int carry = 0;
    string ans = "";
    while (i >= 0 || j >= 0)
    {
        if (i >= 0)
        {
            sum += (a[i] - '0');
            i--;
        }
        if (j >= 0)
        {
            sum += (b[j] - '0');
            j--;
        }
        sum += carry;
        carry = 0;
        if (sum >= 2)
        {
            carry = 1;
            sum -= 2;
        }
        ans += ('0' + sum);
        sum = 0;
    }
    if (carry > 0)
    {
        ans += ('0' + carry);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cout << addBinary("1", "11");
}