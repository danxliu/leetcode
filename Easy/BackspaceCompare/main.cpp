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

bool backspaceCompare(string s, string t)
{
    stack<char> ss;
    stack<char> ts;
    for (int i = 0; i < s.size(); i++)
    {
        if (!ss.empty() && s[i] == '#')
            ss.pop();
        else if (s[i] != '#')
            ss.push(s[i]);
    }

    for (int i = 0; i < t.size(); i++)
    {
        if (!ts.empty() && t[i] == '#')
            ts.pop();
        else if (t[i] != '#')
            ts.push(t[i]);
    }
    return ss == ts;
}

int main()
{
    cout << backspaceCompare("a#c", "b");
}