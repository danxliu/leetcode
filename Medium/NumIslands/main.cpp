#include <bits/stdc++.h>
using namespace std;

int numIslands(vector<vector<char>> &grid)
{
    int cis = 2;
    queue<pair<int, int>> q;
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                grid[i][j] = '0';
                q.push({i, j});
                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        pair<int, int> next = {cur.first + dx[k], cur.second + dy[k]};
                        if (next.first < 0 || next.second < 0 || next.first >= grid.size() || next.second >= grid[0].size() || grid[next.first][next.second] != '1')
                            continue;
                        grid[next.first][next.second] = '0';
                        q.push({next.first, next.second});
                    }
                }
                cis++;
            }
        }
    }
    return cis - 1;
}