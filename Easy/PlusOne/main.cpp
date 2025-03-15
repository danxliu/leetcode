#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        digits[i] += carry;
        if (digits[i] == 10)
        {
            digits[i] = 0;
            carry = 1;
        }
        else
        {
            return digits;
        }
    }
    if (carry > 0)
    {
        digits.insert(digits.begin(), carry);
    }
    return digits;
}

int main()
{
    vector<int> digits = {9};
    vector<int> plusone = plusOne(digits);
    for (int i = 0; i < plusone.size(); i++)
    {
        cout << plusone[i] << " ";
    }
    cout << endl;
}