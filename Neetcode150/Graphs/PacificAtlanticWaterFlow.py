from collections import deque
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n = len(heights)
        m = len(heights[0])

        pacVis = set()
        atVis = set()
        
        dr = [0, 1, -1, 0]
        dc = [1, 0, 0, -1]
        
        def bfs(q, vis):
            while len(q) > 0:
                cr, cc = q.popleft()
                for i in range(4):
                    nr, nc = cr + dr[i], cc + dc[i]
                    
                    if nr < 0 or nc < 0 or nr >= n or nc >= m:
                        continue
                    if (nr, nc) in vis or heights[nr][nc] < heights[cr][cc]:
                        continue
                    
                    vis.add((nr, nc))
                    q.append((nr, nc))
        
        # pacific
        q = deque()
        for i in range(n):
            q.append((i, 0))
            pacVis.add((i, 0))
        for i in range(m):
            q.append((0, i))
            pacVis.add((0, i))
        bfs(q, pacVis)
        q.clear()
        for i in range(n):
            q.append((i, m-1))
            atVis.add((i, m-1))
        for i in range(m):
            q.append((n-1, i))
            atVis.add((n-1, i))
        bfs(q, atVis)
        
        ans = []
        for i in range(n):
            for j in range(m):
                if (i, j) in pacVis and (i, j) in atVis:
                    ans.append([i, j])
        return ans