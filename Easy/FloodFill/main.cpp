#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};

    queue<pair<int, int>> q;
    int c = image[sr][sc];
    if (c == color)
    {
        return image;
    }
    q.push({sr, sc});
    image[sr][sc] = color;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> n = {cur.first + dx[i], cur.second + dy[i]};
            if (n.first < 0 || n.second < 0 || n.first >= image.size() || n.second >= image[0].size() || image[n.first][n.second] != c)
                continue;
            image[n.first][n.second] = color;
            q.push(n);
        }
    }
    return image;
}