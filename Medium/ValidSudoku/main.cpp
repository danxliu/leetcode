#include <iostream>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == '.')
                continue;
            for (int k = 0; k < 9; k++)
            {
                if (board[i][k] == board[i][j] && k != j)
                    return false;
                if (board[k][j] == board[i][j] && k != i)
                    return false;
            }
            // check small box
            int sx = i / 3;
            int sy = j / 3;
            for (int k = sx * 3; k < (sx * 3 + 3); k++)
            {
                for (int l = sy * 3; l < (sy * 3 + 3); l++)
                {
                    if (k == i && l == j)
                        continue;
                    if (board[k][l] == board[i][j])
                        return false;
                }
            }
        }
    }
    return true;
}

int main()
{
}