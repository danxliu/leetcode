#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<char> posSolns[9][9]; // represents possible solutions in each cell

bool isSolved(vector<vector<char>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == '.')
            {
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (int k = 1; k <= 9; k++)
                {
                    posSolns[i][j].insert('0' + k);
                }
            }
            else
            {
                posSolns[i][j].insert(board[i][j]);
            }
        }
    }
    while (!isSolved(board))
    {
        int changed = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                // remove value from rows and columns of posSolns
                if (board[i][j] == '.')
                    continue;
                for (int k = 0; k < 9; k++)
                {
                    if (i != k && posSolns[k][j].find(board[i][j]) != posSolns[k][j].end())
                    {
                        changed++;
                        posSolns[k][j].erase(posSolns[k][j].find(board[i][j]));
                        if (posSolns[k][j].size() == 1)
                        {
                            board[k][j] = *(posSolns[k][j].begin());
                        }
                    }
                    if (j != k && posSolns[i][k].find(board[i][j]) != posSolns[i][k].end())
                    {
                        changed++;
                        posSolns[i][k].erase(posSolns[i][k].find(board[i][j]));
                        if (posSolns[i][k].size() == 1)
                        {
                            board[i][k] = *(posSolns[i][k].begin());
                        }
                    }
                }
                int sx = i / 3;
                int sy = j / 3;
                for (int k = sx * 3; k < (sx * 3 + 3); k++)
                {
                    for (int l = sy * 3; l < (sy * 3 + 3); l++)
                    {
                        if (i == k && j == l)
                            continue;
                        if (posSolns[k][l].find(board[i][j]) != posSolns[k][l].end())
                        {
                            changed++;
                            posSolns[k][l].erase(posSolns[k][l].find(board[i][j]));
                            if (posSolns[k][l].size() == 1)
                            {
                                board[k][l] = *(posSolns[k][l].begin());
                            }
                        }
                    }
                }
            }
        }
        for (int r = 0; r < board.size(); r++)
        {
            for (int c = 0; c < board[r].size(); c++)
            {
                cout << board[r][c] << " ";
            }
            cout << endl;
        }
        cout << endl;
        if (changed == 0)
            break;
    }
}

int main()
{
    vector<vector<char>> board = {{'.', '.', '9', '7', '4', '8', '.', '.', '.'}, {'7', '.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '2', '.', '1', '.', '9', '.', '.', '.'}, {'.', '.', '7', '.', '.', '.', '2', '4', '.'}, {'.', '6', '4', '.', '1', '.', '5', '9', '.'}, {'.', '9', '8', '.', '.', '.', '3', '.', '.'}, {'.', '.', '.', '8', '.', '3', '.', '2', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '6'}, {'.', '.', '.', '2', '7', '5', '9', '.', '.'}};
    solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (auto it = posSolns[i][j].begin(); it != posSolns[i][j].end(); it++)
            {
                cout << (*it) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}