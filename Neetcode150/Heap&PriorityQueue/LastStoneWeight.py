from typing import List
import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = []
        for stone in stones:
            # max heap
            heapq.heappush(heap, -1 * stone)
        
        while len(heap) > 1:
            i = -1 * heapq.heappop(heap)
            j = -1 * heapq.heappop(heap)
            if i-j != 0:
                heapq.heappush(heap, -1 * abs(i-j))
        if not len(heap):
            return 0
        return -1*heap[0]

