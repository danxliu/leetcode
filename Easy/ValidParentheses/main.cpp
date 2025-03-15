#include <iostream>
#include <map>
#include <stack>
using namespace std;

bool isValid(string s)
{
    map<char, int> parentheses;
    parentheses.insert(make_pair('(', 0));
    parentheses.insert(make_pair('{', 0));
    parentheses.insert(make_pair('[', 0));
    map<char, char> opp;
    opp.insert(make_pair(')', '('));
    opp.insert(make_pair('}', '{'));
    opp.insert(make_pair(']', '['));
    stack<char> inst;
    for (int i = 0; i < s.size(); i++)
    {
        if (parentheses.find(s[i]) != parentheses.end())
        {
            // cout << "Pushing " << s[i] << endl;
            inst.push(s[i]);
        }
        else
        {
            // cout << "Checking " << inst.top() << " " << s[i] << endl;
            if (inst.size() == 0)
                return false;
            char c = inst.top();
            inst.pop();
            if (c != opp[s[i]])
            {
                return false;
            }
        }
    }
    if (inst.size() != 0)
        return false;
    return true;
}

int main()
{
    cout << isValid("([)]");
}