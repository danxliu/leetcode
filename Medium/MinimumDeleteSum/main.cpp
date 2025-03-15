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

int minimumDeleteSum(string s1, string s2)
{
    int dp[s1.size() + 1][s2.size() + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= s1.size(); i++)
    {
        dp[i][0] = dp[i - 1][0] + (int)s1[i - 1];
    }
    for (int i = 1; i <= s2.size(); i++)
    {
        dp[0][i] = dp[0][i - 1] + (int)s2[i - 1];
    }
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j] + (int)s1[i - 1], dp[i][j - 1] + (int)s2[j - 1]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}

int main()
{
    cout << minimumDeleteSum("eat", "sea");
}