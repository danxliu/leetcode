#include <iostream>
using namespace std;

int reverse(int x)
{
    bool negative = false;
    if (x < 0)
    {
        negative = true;
        x *= (-1);
    }
    int result = 0;
    int it = 0;
    while (x > 9 && it < 10)
    {
        result += x % 10; //get last digit of x
        result *= 10;
        x /= 10;
        it++;
    }
    if (it >= 10)
    {
        return 0;
    }
    result += x;
    if (negative)
    {
        result *= (-1);
    }
    return result;
}

int main()
{
    int temp;
    cin >> temp;
    cout << reverse(temp);
}