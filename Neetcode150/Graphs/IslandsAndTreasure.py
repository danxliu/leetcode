from collections import deque

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        n = len(grid)
        m = len(grid[0])
        q = deque()
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0:
                    q.append((i, j, 0))
        
        dr = [1, 0, 0, -1]
        dc = [0, -1, 1, 0]
        while len(q) > 0:
            cr, cc, cd = q.popleft()
            for i in range(4):
                nr, nc = cr + dr[i], cc + dc[i]
                
                if nr < 0 or nc < 0 or nr >= n or nc >= m:
                    continue
                
                if grid[nr][nc] == -1 or cd >= grid[nr][nc]:
                    continue
                    
                grid[nr][nc] = cd+1
                q.append((nr, nc, cd+1))
        return