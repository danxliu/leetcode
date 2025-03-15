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

int minInsertions(string s)
{
    int dp[s.size() + 1][s.size() + 1];
    string sr = s;
    reverse(sr.begin(), sr.end());

    for (int i = 0; i <= s.size(); i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= s.size(); j++)
        {
            if (s[i - 1] == sr[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return s.size() - dp[s.size()][s.size()];
}

int main()
{
    cout << minInsertions("zzazz");
}