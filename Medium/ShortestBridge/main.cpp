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

int shortestBridge(vector<vector<int>> &grid)
{
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};
    set<pair<int, int>> isPos[2];
    // floodfill to get the locations of each island
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1 && isPos[0].find({i, j}) == isPos[0].end() && isPos[1].find({i, j}) == isPos[1].end())
            {
                // just bfs or something
                queue<pair<int, int>> q;
                q.push({i, j});
                int isNum = isPos[0].size() == 0 ? 0 : 1;
                isPos[isNum].insert({i, j});
                while (!q.empty())
                {
                    pair<int, int> c = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        pair<int, int> n = {c.first + dx[k], c.second + dy[k]};
                        if (n.first < 0 || n.first >= grid.size() || n.second < 0 || n.second >= grid[n.first].size() || grid[n.first][n.second] != 1)
                            continue;
                        if (isPos[isNum].find(n) == isPos[isNum].end())
                        {
                            isPos[isNum].insert(n);
                            q.push(n);
                        }
                    }
                }
            }
        }
    }

    // loop through each of sets and find shortest distance
    int ans = INT_MAX;
    for (auto i = isPos[0].begin(); i != isPos[0].end(); i++)
    {
        for (auto j = isPos[1].begin(); j != isPos[1].end(); j++)
        {
            ans = min(ans, abs(i->first - j->first) + abs(i->second - j->second));
        }
    }
    return ans;
}

int main()
{
}