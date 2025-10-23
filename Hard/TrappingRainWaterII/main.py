import heapq
from typing import List

class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        n = len(heightMap)
        m = len(heightMap[0])

        vis = set()
        pq = []

        for i in range(n):
            heapq.heappush(pq, (heightMap[i][0], i, 0))
            heapq.heappush(pq, (heightMap[i][m-1], i, m-1))
            vis.add((i, 0))
            vis.add((i, m-1))
        for i in range(m):
            heapq.heappush(pq, (heightMap[0][i], 0, i))
            heapq.heappush(pq, (heightMap[n-1][i], n-1, i))
            vis.add((0, i))
            vis.add((n-1, i))

        dr = [0, 1, -1, 0]
        dc = [1, 0, 0, -1]

        ans = 0
        while pq:
            ch, cr, cc = heapq.heappop(pq)
            for i in range(4):
                nr, nc = cr + dr[i], cc + dc[i]

                if nr < 0 or nc < 0 or nr >= n or nc >= m:
                    continue
                if (nr, nc) in vis:
                    continue
                nh = heightMap[nr][nc]
                vis.add((nr, nc))
                if nh < ch:
                    ans += (ch - nh)
                heapq.heappush(pq, (max(nh, ch), nr, nc))
        return ans