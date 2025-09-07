from typing import List
import heapq

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.heap = []
        self.k = k
        for num in nums:
            self.add(num)

    def add(self, val: int) -> int:
        heapq.heappush(self.heap, val)
        if len(self.heap) > self.k:
            heapq.heappop(self.heap)
        return self.heap[0]

kthLargest = KthLargest(3, [1, 2, 3, 3])
print(kthLargest.add(3))
print(kthLargest.add(5))
print(kthLargest.add(6))
print(kthLargest.add(7))
print(kthLargest.add(8))
