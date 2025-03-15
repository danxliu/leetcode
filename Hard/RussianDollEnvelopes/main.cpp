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

bool compare(vector<int> &a, vector<int> &b)
{
    if (a[0] < b[0])
    {
        return true;
    }
    if (a[0] == b[0] && a[1] > b[1])
    {
        return true;
    }
    return false;
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), compare);
    vector<int> dp;
    dp.push_back(envelopes[0][1]);
    for (int i = 0; i < envelopes.size(); i++)
    {
        int cur = envelopes[i][1];
        if (dp.back() < cur)
        {
            dp.push_back(cur);
        }
        else
        {
            int ind = lower_bound(dp.begin(), dp.end(), cur) - dp.begin();
            dp[ind] = cur;
        }
    }
    return dp.size();
}

int main()
{
}