#include <iostream>
#include <vector>
using namespace std;

// bool isValid(int r, int c, char ch, vector<vector<char>> &board)
// {
//     for (int i = 0; i < 9; i++)
//     {
//         if (board[i][c] == ch || board[r][i] == ch)
//             return false;
//     }
//     for (int i = (r / 3); i < (r / 3) + 3; i++)
//     {
//         for (int j = (c / 3); j < (c / 3) + 3; j++)
//         {
//             if (board[i][j] == ch)
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// bool solve(vector<vector<char>> &board)
// {
//     for (int i = 0; i < board.size(); i++)
//     {
//         for (int j = 0; j < board[i].size(); j++)
//         {
//             if (board[i][j] == '.')
//             {
//                 for (char k = '1'; k <= '9'; k++)
//                 {
//                     if (isValid(i, j, k, board))
//                     {
//                         board[i][j] = k;
//                         if (solve(board))
//                         {
//                             return true;
//                         }
//                         else
//                         {
//                             board[i][j] = '.';
//                         }
//                     }
//                 }
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// void solveSudoku(vector<vector<char>> &board)
// {
//     solve(board);
// }

bool isValid(int r, int c, char k, vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
        if (board[i][c] == k || board[r][i] == k || board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == k)
        {
            return false;
        }
    return true;
}
bool recurse(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char k = '1'; k <= '9'; k++)
                {
                    if (isValid(i, j, k, board))
                    {
                        board[i][j] = k;
                        if (recurse(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>> &board)
{
    recurse(board);
}

int main()
{
    vector<vector<char>> board = {{'.', '.', '9', '7', '4', '8', '.', '.', '.'}, {'7', '.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '2', '.', '1', '.', '9', '.', '.', '.'}, {'.', '.', '7', '.', '.', '.', '2', '4', '.'}, {'.', '6', '4', '.', '1', '.', '5', '9', '.'}, {'.', '9', '8', '.', '.', '.', '3', '.', '.'}, {'.', '.', '.', '8', '.', '3', '.', '2', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '6'}, {'.', '.', '.', '2', '7', '5', '9', '.', '.'}};
    solveSudoku(board);
    for (int r = 0; r < board.size(); r++)
    {
        for (int c = 0; c < board[r].size(); c++)
        {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}