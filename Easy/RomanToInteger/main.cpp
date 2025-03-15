#include <iostream>
#include <map>
using namespace std;

map<char, int> values;

int romanToInt(string s)
{
    int sum = 0;
    values.insert(make_pair('I', 1));
    values.insert(make_pair('V', 5));
    values.insert(make_pair('X', 10));
    values.insert(make_pair('L', 50));
    values.insert(make_pair('C', 100));
    values.insert(make_pair('D', 500));
    values.insert(make_pair('M', 1000));
    for (int i = 0; i < s.size(); i++)
    {
        string cur = s.substr(i, 2);
        cout << cur << endl;
        if (cur == "IV")
        {
            sum += 4;
            i++;
        }
        else if (cur == "IX")
        {
            sum += 9;
            i++;
        }
        else if (cur == "XL")
        {
            sum += 40;
            i++;
        }
        else if (cur == "XC")
        {
            sum += 90;
            i++;
        }
        else if (cur == "CD")
        {
            sum += 400;
            i++;
        }
        else if (cur == "CM")
        {
            sum += 900;
            i++;
        }
        else
        {
            sum += values[cur[0]];
        }
    }
    return sum;
}

int main()
{
    cout << romanToInt("MCMXCIV");
}