#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    int reverse = 0;
    int temp = x;
    while (temp >= 10)
    {
        reverse += (temp % 10);
        reverse *= 10;
        temp /= 10;
    }
    reverse += temp;
    // cout << reverse << " " << x << endl;
    if (reverse == x)
    {
        return true;
    }
    return false;
}

int main()
{
    cout << isPalindrome(1234567899) << endl;
}