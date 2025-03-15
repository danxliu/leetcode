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

int dfs(int cnode, vector<vector<int>> &adj, string &s, int &ans)
{
    int l = 0;
    int sl = 0;
    for (int i = 0; i < adj[cnode].size(); i++)
    {
        if (s[adj[cnode][i]] == s[cnode])
            continue;
        int nl = dfs(adj[cnode][i], adj, s, ans);
        if (nl > l)
        {
            sl = l;
            l = nl;
        }
        else if (nl > sl)
            sl = nl;
    }
    ans = max(ans, l + sl + 1);
    return l + 1;
}

int longestPath(vector<int> &parent, string s)
{
    vector<vector<int>> adj;
    adj.assign(parent.size(), vector<int>());
    for (int i = 1; i < parent.size(); i++)
    {
        adj[parent[i]].push_back(i);
    }
    int ans = 1;
    dfs(0, adj, s, ans);
    return ans;
}