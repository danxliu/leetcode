#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve(vector<vector<char>> &board)
{
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    vector<pair<int, int>> plscheck;
    // check border for o's that should not be flipped
    for (int i = 0; i < board.size(); i++)
    {
        plscheck.push_back(make_pair(i, 0));
        plscheck.push_back(make_pair(i, board[i].size() - 1));
    }
    for (int j = 0; j < board[0].size(); j++)
    {
        plscheck.push_back(make_pair(0, j));
        plscheck.push_back(make_pair(board.size() - 1, j));
    }

    // Change visited o's to 0 as visited
    for (int i = 0; i < plscheck.size(); i++)
    {
        if (board[plscheck[i].first][plscheck[i].second] == 'X')
        {
            continue;
        }
        board[plscheck[i].first][plscheck[i].second] = '0';
        queue<pair<int, int>> q;
        q.push(make_pair(plscheck[i].first, plscheck[i].second));
        while (!q.empty())
        {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size())
                    continue;
                if (board[nx][ny] == 'O')
                {
                    board[nx][ny] = '0';
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
            else if (board[i][j] == '0')
            {
                board[i][j] = 'O';
            }
        }
    }
}

int main()
{
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    solve(board);
}