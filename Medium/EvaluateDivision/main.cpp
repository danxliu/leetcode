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

double findAns(map<string, vector<pair<string, double>>> &paths, string cur, double val, string end, map<string, bool> &visited)
{
    // cout << "current " << cur << " " << val << endl;
    if (cur == end)
    {
        return val;
    }
    for (int i = 0; i < paths[cur].size(); i++)
    {
        string n = paths[cur][i].first;
        double c = paths[cur][i].second;
        if (visited[n])
            continue;
        visited[n] = true;
        // cout << "pushing " << n << " " << val * c << endl;
        double ans = findAns(paths, n, val * c, end, visited);
        visited[n] = false;
        if (ans != -1.0)
            return ans;
    }
    return -1.0;
}

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    int n = equations.size();
    map<string, vector<pair<string, double>>> paths;
    map<string, bool> visited;
    for (int i = 0; i < n; i++)
    {
        paths[equations[i][0]].push_back({equations[i][1], values[i]});
        paths[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        visited[equations[i][0]] = false;
        visited[equations[i][1]] = false;
    }
    vector<double> ans;
    for (int i = 0; i < queries.size(); i++)
    {
        if (paths.find(queries[i][0]) == paths.end() || paths.find(queries[i][1]) == paths.end())
        {
            ans.push_back(-1);
            continue;
        }
        ans.push_back(findAns(paths, queries[i][0], 1.0, queries[i][1], visited));
        for (auto it = visited.begin(); it != visited.end(); it++)
        {
            it->second = false;
        }
    }
    return ans;
}

int main()
{
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}, {"a", "c"}, {"d", "e"}};
    vector<double> values = {2.0, 3.0, 6.0, 1.0};
    vector<vector<string>> queries = {{"a", "c"},
                                      {"b", "c"},
                                      {"a", "e"},
                                      {"a", "a"},
                                      {"x", "x"},
                                      {"a", "d"}};
    vector<double>
        ans = calcEquation(equations, values, queries);
    for (auto &i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}