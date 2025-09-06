from typing import *

class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        memo = {}

        n = len(matrix)
        m = len(matrix[0])

        dr = [0, 1, -1, 0]
        dc = [1, 0, 0, -1]

        def helper(i, j):
            if (i, j) in memo.keys():
                return memo[(i, j)]
            
            memo[(i, j)] = 1
            v = matrix[i][j]
            for k in range(4):
                ni = i + dr[k]
                nj = j + dc[k]
                if ni < 0 or nj < 0 or ni >= n or nj >= m:
                    continue
                nv = matrix[ni][nj]
                if nv <= v:
                    continue
                memo[(i, j)] = max(memo[(i, j)], helper(ni, nj) + 1)
            return memo[(i, j)]

        ans = 0
        for i in range(n):
            for j in range(m):
                ans = max(ans, helper(i, j))
        return ans

s = Solution()
print(s.longestIncreasingPath([[1,2,3],[2,1,4],[7,6,5]]))