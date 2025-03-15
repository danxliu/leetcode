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

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
vector<vector<bool>> vis;

bool dfs(int x, int y, vector<vector<char>> &board, string word, vector<vector<bool>> &vis)
{
    if (word.size() == 0)
        return true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size() || board[nx][ny] != word[0] || vis[nx][ny])
            continue;
        vis[nx][ny] = true;
        if (dfs(nx, ny, board, word.substr(1), vis))
            return true;
        vis[nx][ny] = false;
    }
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    vis.assign(board.size(), vector<bool>());
    for (int k = 0; k < board.size(); k++)
    {
        vis[k].assign(board[k].size(), false);
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == word[0])
            {
                vis[i][j] = true;
                if (dfs(i, j, board, word.substr(1), vis))
                    return true;
                vis[i][j] = false;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> grid = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'E', 'S'},
        {'A', 'D', 'E', 'E'}};
    cout << exist(grid, "ABCEFSADEESE");
}