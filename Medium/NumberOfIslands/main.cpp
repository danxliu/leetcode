#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int numIslands(vector<vector<char>> &grid)
{
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    int nums = 0;
    char c = 'I';
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] != '1')
                continue;
            nums++;
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            grid[i][j] = c;
            while (!q.empty())
            {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int nx = cx + dx[k];
                    int ny = cy + dy[k];
                    if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
                    {
                        continue;
                    }
                    if (grid[nx][ny] == '1')
                    {
                        q.push(make_pair(nx, ny));
                        grid[nx][ny] = c;
                    }
                }
            }
        }
    }
    cout << nums << endl;
    return nums;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    numIslands(grid);
}