from typing import List
import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        
        for point in points:
            heapq.heappush(heap, (-1*(point[0]**2 + point[1]**2), point[0], point[1]))
            if len(heap) > k:
                heapq.heappop(heap)
        
        ans = []
        for i in heap:
            ans.append([i[1], i[2]])
        return ans