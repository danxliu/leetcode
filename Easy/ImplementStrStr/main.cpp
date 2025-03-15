#include <iostream>
using namespace std;

int strStr(string haystack, string needle)
{
    int f = haystack.find(needle);
    if (f != string::npos)
    {
        return f;
    }
    return -1;
}

int main()
{
    cout << strStr("hello", "ll");
}