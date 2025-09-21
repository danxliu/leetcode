from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = deque()
        
        n = len(grid)
        m = len(grid[0])
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    q.append((i, j, 0))
        
        dr = [1, 0, 0, -1]
        dc = [0, -1, 1, 0]
        ans = 0
        while len(q) > 0:
            cr, cc, ct = q.popleft()
            
            for i in range(4):
                nr, nc = cr + dr[i], cc + dc[i]
                nt = ct + 1
                if nr < 0 or nc < 0 or nr >= n or nc >= m:
                    continue
                if grid[nr][nc] != 1:
                    continue
                grid[nr][nc] = 2
                ans = max(ans, nt)
                q.append((nr, nc, nt))
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    return -1
        return ans