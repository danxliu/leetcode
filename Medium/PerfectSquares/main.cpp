#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int dp[10001];
        dp[0] = 0;
        for (int i=1; i<=n; i++)
        {
            int mn = 10001;
            int x = 1;
            while (x*x <= i)
            {
                mn = min(mn, dp[i - x*x] + 1);
                x++;
            }
            dp[i] = mn;
        }
        return dp[n];
    }
};

int main()
{
    int n = 12;
    Solution s;
    cout << s.numSquares(n) << endl;
}