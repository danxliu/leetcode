#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

bool valid(set<pair<int, int>> queens, int row, int col)
{
    for (auto it = queens.begin(); it != queens.end(); it++)
    {
        if (row == (*it).first || col == (*it).second || abs(row - (*it).first) == abs(col - (*it).second))
        {
            return false;
        }
    }
    return true;
}

vector<vector<string>> helper(set<pair<int, int>> queens, int row, int n)
{
    vector<vector<string>> ans;
    if (row == n)
    {
        vector<string> board;
        for (int i = 0; i < n; i++)
        {
            string temp = "";
            for (int j = 0; j < n; j++)
            {
                if (queens.find({i, j}) != queens.end())
                {
                    temp += "Q";
                }
                else
                {
                    temp += ".";
                }
            }
            board.push_back(temp);
        }
        ans.push_back(board);
        return ans;
    }
    for (int i = 0; i < n; i++)
    {
        if (valid(queens, row, i))
        {
            queens.insert({row, i});
            vector<vector<string>> res = helper(queens, row + 1, n);
            for (int j = 0; j < res.size(); j++)
            {
                ans.push_back(res[j]);
            }
            queens.erase({row, i});
        }
    }
    return ans;
}

vector<vector<string>> solveNQueens(int n)
{
    set<pair<int, int>> queens;
    vector<vector<string>> ans = helper(queens, 0, n);
    return ans.size();
}

int main()
{
    vector<vector<string>> ans = solveNQueens(9);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }
}