from typing import List
import heapq

class Solution:
    def dist(self, a, b):
        return abs(a[0] - b[0]) + abs(a[1] - b[1])

    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        q = []
        vis = set()
        heapq.heappush(q, (0, points[0]))
        ans = 0

        while len(q) > 0:
            curCost, curPoint = heapq.heappop(q)
            if (curPoint[0], curPoint[1]) in vis:
                continue
            vis.add((curPoint[0], curPoint[1]))
            ans += curCost

            for point in points:
                heapq.heappush(q, (self.dist(curPoint, point), point))
    
        return ans