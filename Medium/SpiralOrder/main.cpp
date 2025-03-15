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

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<vector<bool>> visited;
    vector<int> ans;
    visited.assign(matrix.size(), vector<bool>());
    for (int i = 0; i < matrix.size(); i++)
    {
        visited[i].assign(matrix[i].size(), false);
    }
    int steps = 1;
    pair<int, int> pos;
    pair<int, int> dirs[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    int dir = 0;
    visited[pos.first][pos.second] = true;
    ans.push_back(matrix[pos.first][pos.second]);
    while (steps < matrix.size() * matrix[0].size())
    {
        pair<int, int> npos = {pos.first + dirs[dir].first, pos.second + dirs[dir].second};
        if (npos.first >= 0 && npos.first < matrix.size() && npos.second >= 0 && npos.second < matrix[0].size() && !visited[npos.first][npos.second])
        {
            pos.first = npos.first;
            pos.second = npos.second;
            ans.push_back(matrix[pos.first][pos.second]);
            visited[pos.first][pos.second] = true;
            steps++;
        }
        else
        {
            dir += 1;
            dir %= 4;
        }
    }
    return ans;
}

int main()
{
}