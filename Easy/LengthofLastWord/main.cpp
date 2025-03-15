#include <iostream>
using namespace std;

int lengthOfLastWord(string s)
{
    int endspaces = 0;
    for (int j = s.size() - 1; j >= 0; j--)
    {
        if (s[j] == ' ')
        {
            endspaces++;
        }
        else
        {
            break;
        }
    }
    s = s.substr(0, s.size() - endspaces);
    int i = s.rfind(' ');
    if (i == string::npos)
    {
        return s.size();
    }
    i++;
    string word = s.substr(i);
    return word.size();
}

int main()
{
    cout << lengthOfLastWord("moon  ");
}