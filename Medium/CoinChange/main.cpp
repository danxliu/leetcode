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

int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (const int &j : coins)
        {
            dp[i] = min(dp[i], (i >= j ? dp[i - j] + 1 : INT_MAX));
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    cout << coinChange(coins, 100);
}