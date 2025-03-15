#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int dx[4] = {0, 1};
    int dy[4] = {1, 0};
    bool visited[201][201];

    struct qinfo {
        int x;
        int y;
        int d;
        bool operator < (const qinfo &o) const
        {
            return d > o.d;
        }
    };

    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i< grid.size(); i++)
        {
            for (int j=0; j<grid[i].size(); j++)
            {
                visited[i][j] = false;
            }
        }
        //starting at top left, dijkstra to bottom right
        priority_queue<qinfo> q;
        q.push(qinfo{0, 0, grid[0][0]});
        visited[0][0] = true;
        while (!q.empty())
        {
            qinfo cur = q.top();
            q.pop();
            if (cur.x == grid.size()-1 && cur.y == grid[0].size() - 1)
            {
                return cur.d;
            }
            for (int i = 0; i < 2; i++)
            {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || visited[nx][ny])
                {
                    continue;
                }
                visited[nx][ny] = true;
                q.push(qinfo{nx, ny, cur.d + grid[nx][ny]});
            }
        }
        return 0;
    }
};

int main()
{
    vector<vector<int> > grid = {{1,3,1},{1,5,1},{4,2,1}};
    Solution s;
    cout << s.minPathSum(grid) << endl;
}
