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

double new21Game(int n, int k, int maxPts)
{
    double dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
    double window = 0;
    if (k > 0)
    {
        window = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = window / maxPts;
        if (i < k)
        {
            window += dp[i];
        }
        if (i - maxPts >= 0 && i - maxPts < k)
        {
            window -= dp[i - maxPts];
        }
    }
    double ans = 0;
    for (int i = k; i <= n; i++)
    {
        ans += dp[i];
    }
    return ans;
}

int main()
{
    cout << new21Game(21, 17, 10);
}