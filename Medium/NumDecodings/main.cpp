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
// -----------------------------------------------------------

int numDecodings(string s)
{
    int dp[s.size() + 1];
    for (int i = 0; i <= s.size(); i++)
    {
        dp[i] = 0;
    }
    if (s[0] != '0')
    {
        dp[0] = 1;
    }
    for (int i = 1; i <= s.size(); i++)
    {
        // two options: 1 - 9 letters, 10 - 26 letters
        int num1 = s[i - 1] - '0';
        int num2 = -1;
        if (i >= 2)
        {
            num2 = stoi(s.substr(i - 2, 2));
        }
        dp[i] = (num1 != 0 ? dp[i - 1] : 0) + (num2 >= 10 && num2 <= 26 ? dp[i - 2] : 0);
    }
    return dp[s.size()];
}

int main()
{
    cout << numDecodings("11106");
}