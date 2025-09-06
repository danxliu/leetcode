from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        n = len(grid)
        m = len(grid[0])

        dr = [0, 1, -1, 0]
        dc = [1, 0, 0, -1]

        def floodfill(r, c):
            for k in range(4):
                nr = r + dr[k]
                nc = c + dc[k]
                if nr < 0 or nc < 0 or nr >= n or nc >= m:
                    continue
                if grid[nr][nc] != "1":
                    continue
                grid[nr][nc] = "-1"
                floodfill(nr, nc)

        numIslands = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] != "1":
                    continue
                numIslands += 1
                floodfill(i, j)
        return numIslands

