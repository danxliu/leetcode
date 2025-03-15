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

int countGoodStrings(int low, int high, int zero, int one)
{
    long long dp[high + 1];
    for (int i = 0; i <= high; i++)
    {
        dp[i] = 0;
    }
    if (one <= high)
    {
        dp[one] += 1;
    }
    if (zero <= high)
    {
        dp[zero] += 1;
    }
    for (int i = 0; i <= high; i++)
    {
        dp[i] += (i >= zero ? dp[i - zero] : 0) + (i >= one ? dp[i - one] : 0);
    }
    long long ans = 0;
    for (int i = low; i <= high; i++)
    {
        ans += dp[i];
        ans %= 1000000007;
    }
    return ans;
}

int main()
{
    cout << countGoodStrings(2, 3, 1, 2);
}