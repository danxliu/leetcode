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

int change(int amount, vector<int> &coins)
{
    int dp[coins.size() + 1][amount + 1];
    for (int i = 0; i <= coins.size(); i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i <= coins.size(); i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= coins.size(); i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            dp[i][j] = dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);
        }
    }
    return dp[coins.size()][amount];
}

int main()
{
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << change(amount, coins);
}