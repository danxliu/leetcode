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

int dfs(int cnode, int pnode, vector<vector<int>> &adj, vector<bool> &hasApple)
{
    int t = 0;
    for (int i = 0; i < adj[cnode].size(); i++)
    {
        if (pnode == adj[cnode][i])
            continue;
        int nt = dfs(adj[cnode][i], cnode, adj, hasApple);
        // If we have to visit the child
        if (nt || hasApple[adj[cnode][i]])
            t += nt + 2;
    }
    return t;
}

int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{
    vector<vector<int>> adj;
    adj.assign(n, vector<int>());
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    return dfs(0, -1, adj, hasApple);
}