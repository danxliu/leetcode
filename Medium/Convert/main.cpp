#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
const int INF = 1e9;
const ll LLINF = 4 * 1e18;
const ll MOD = 1e9 + 7;
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef vector<iii> viii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
typedef set<ll> sl;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> lll;
typedef vector<pll> vll;
typedef vector<lll> vlll;
typedef priority_queue<ll> pql;
typedef stack<ll> stl;
typedef queue<ll> ql;
typedef deque<ll> dl;
typedef map<ll, ll> mll;
#define f first
#define s second
// -----------------------------------------------------------

bool onePass(vector<vector<char>> &zigzag, int c, int &i, string s, int numRows)
{
    for (int j = 0; j < numRows; j++)
    {
        if (i == s.size())
        {
            return false;
        }
        zigzag[j][c] = s[i++];
    }
    for (int j = 1; j < numRows - 1; j++)
    {
        if (i == s.size())
        {
            return false;
        }
        zigzag[numRows - j - 1][c + j] = s[i++];
    }
    return true;
}

string convert(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    int numCols = s.size();
    vector<vector<char>> zigzag;
    zigzag.assign(numRows, vector<char>());
    for (int i = 0; i < numRows; i++)
    {
        zigzag[i].assign(numCols, ' ');
    }
    int c = 0;
    int ind = 0;
    while (onePass(zigzag, c, ind, s, numRows))
    {
        c += (numRows - 1);
    }
    string ans = "";
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            cout << zigzag[i][j] << " ";
            if (zigzag[i][j] != ' ')
            {
                ans += zigzag[i][j];
            }
        }
        cout << endl;
    }
    return ans;
}

int main()
{
    cout << convert("PAYPALISHIRING", 9);
}