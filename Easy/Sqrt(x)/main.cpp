#include <iostream>
using namespace std;

int mySqrt(int x)
{
    for (int i = 0; i <= x; i++)
    {
        if (i * i == x)
        {
            return i;
        }
        else if (i * i > x)
        {
            return i - 1;
        }
    }
    return 0;
}

int main()
{
    cout << mySqrt(1);
}