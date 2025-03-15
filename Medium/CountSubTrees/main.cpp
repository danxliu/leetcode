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
vector<int> ans;

vector<int> dfs(int cnode, int pnode, string &labels, vector<vector<int>> &adj)
{
    vector<int> ch;
    ch.assign(26, 0);
    ch[labels[cnode] - 'a'] = 1;
    for (int i = 0; i < adj[cnode].size(); i++)
    {
        if (adj[cnode][i] == pnode)
            continue;
        vector<int> tmp = dfs(adj[cnode][i], cnode, labels, adj);
        for (int j = 0; j < tmp.size(); j++)
        {
            ch[j] += tmp[j];
        }
    }
    ans[cnode] = ch[labels[cnode] - 'a'];
    return ch;
}

vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
{
    vector<vector<int>> adj;
    adj.assign(n, vector<int>());
    ans.assign(labels.size(), 0);
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    dfs(0, -1, labels, adj);
    return ans;
}