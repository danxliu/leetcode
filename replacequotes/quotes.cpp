#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin ("in.txt");
ofstream fout ("out.txt");

int main()
{
    string s;
    fin >> s;
    for (int i=0; i<s.size(); i++)
    {
        if(s[i] == '\"')
            s[i] = '\'';
    }
    fout << s << endl;
}