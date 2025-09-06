from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        n = len(grid)
        m = len(grid[0])

        dr = [0, 1, -1, 0]
        dc = [1, 0, 0, -1]

        def floodfill(r, c):
            size = 1
            for k in range(4):
                nr = r + dr[k]
                nc = c + dc[k]
                if nr < 0 or nc < 0 or nr >= n or nc >= m:
                    continue
                if grid[nr][nc] != "1":
                    continue
                grid[nr][nc] = "-1"
                size += floodfill(nr, nc)
            return size

        maxSize = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] != "1":
                    continue
                maxSize = max(maxSize, floodfill(i, j))
        return maxSize

