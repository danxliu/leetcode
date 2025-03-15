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

void gameOfLife(vector<vector<int>> &board)
{
    set<pair<int, int>> delta;
    int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            int numAlive = 0;
            for (int k = 0; k < 8; k++)
            {
                pair<int, int> n = {i + dx[k], j + dy[k]};
                if (n.first >= 0 && n.first < board.size() && n.second >= 0 && n.second < board[n.first].size() && board[n.first][n.second])
                {
                    numAlive++;
                }
            }
            if (!board[i][j])
            {
                if (numAlive == 3)
                {
                    delta.insert({i, j});
                }
                continue;
            }
            if (board[i][j])
            {
                if (numAlive < 2 || numAlive > 3)
                {
                    delta.insert({i, j});
                }
            }
        }
    }
    for (auto it = delta.begin(); it != delta.end(); it++)
    {
        board[it->first][it->second] = !board[it->first][it->second];
    }
}

int main()
{
}