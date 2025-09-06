from typing import *

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        dp = [[0] * n for i in range(m)]
        dp[0][0] = 1 # 1 path to start at position 0, 0

        for i in range(m):
            for j in range(n):
                up = 0 if i == 0 else dp[i-1][j]
                left = 0 if j == 0 else dp[i][j-1]

                dp[i][j] = max(dp[i][j], up + left)
        
        return dp[m-1][n-1]

s = Solution()

print(s.uniquePaths(3, 3))