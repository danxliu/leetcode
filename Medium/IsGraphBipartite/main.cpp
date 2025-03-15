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

bool helper(int cg, int u, vector<int> &vertices, vector<vector<int>> &graph)
{
    bool ans = true;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (vertices[v] == -1)
        {
            vertices[v] = (cg + 1) % 2;
            ans = ans && helper((cg + 1) % 2, graph[u][i], vertices, graph);
            if (!ans)
            {
                return false;
            }
        }
        else if (vertices[v] != (cg + 1) % 2)
        {
            return false;
        }
    }
    return ans;
}

bool isBipartite(vector<vector<int>> &graph)
{
    vector<int> vertices;
    vertices.assign(graph.size(), -1);
    bool ans = true;
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i] == -1)
        {
            ans = ans && helper(0, i, vertices, graph);
        }
        if (!ans)
        {
            return false;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << isBipartite(graph);
}