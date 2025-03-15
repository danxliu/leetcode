#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int minlen = 100000;
    for (int i = 0; i < strs.size(); i++)
    {
        minlen = strs[i].length() < minlen ? strs[i].length() : minlen;
    }
    string s = "";
    for (int i = 0; i < minlen; i++)
    {
        char c = strs[0][i];
        for (int j = 0; j < strs.size(); j++)
        {
            if (strs[j][i] != c)
                return s;
        }
        s += c;
    }
    return s;
}

int main()
{
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");
    cout << longestCommonPrefix(strs);
}