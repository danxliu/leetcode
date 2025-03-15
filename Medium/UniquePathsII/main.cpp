#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[101][101];
        if (obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        for (int i=0; i<101; i++)
        {
            for (int j=0; j<101; j++)
            {
                dp[i][j] = 0;
            }
        }
        for (int i=1; i <= m; i++)
        {
            for (int j=1; j <= n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                if (obstacleGrid[i-1][j-1] == 1)
                {
                    dp[i][j] = 0;
                }
                if (i == 1 and j == 1)
                {
                    dp[i][j] = 1;
                }
            }
        }
        for (int i=1; i<=m; i++)
        {
            for (int j=1; j<n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m][n];
    }
};

int main()
{
    vector <vector <int> > obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
}