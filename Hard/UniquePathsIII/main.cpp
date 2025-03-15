#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

bool valid(vector<vector<bool>> vis)
{
    for (int i = 0; i < vis.size(); i++)
    {
        for (int j = 0; j < vis[i].size(); j++)
        {
            if (!vis[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int dfs(pair<int, int> pos, pair<int, int> end, vector<vector<bool>> vis)
{
    if (pos == end && valid(vis))
        return 1;
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        pair<int, int> n = {pos.first + dx[i], pos.second + dy[i]};
        if (n.first < 0 || n.second < 0 || n.first >= vis.size() || n.second >= vis[n.first].size() || vis[n.first][n.second])
            continue;
        vis[n.first][n.second] = true;
        ans += dfs(n, end, vis);
        vis[n.first][n.second] = false;
    }
    return ans;
}

int uniquePathsIII(vector<vector<int>> &grid)
{
    pair<int, int> st;
    pair<int, int> end;
    vector<vector<bool>> vis;
    vis.assign(grid.size(), vector<bool>());
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            vis[i].push_back(false);
        }
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {
            if (grid[i][j] == -1)
                vis[i][j] = true;
            else if (grid[i][j] == 1)
            {
                st.first = i;
                st.second = j;
                vis[i][j] = true;
            }
            else if (grid[i][j] == 2)
            {
                end.first = i;
                end.second = j;
            }
        }
    }
    return dfs(st, end, vis);
}

int main()
{
    
}