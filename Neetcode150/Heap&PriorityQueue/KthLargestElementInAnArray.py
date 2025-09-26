from heapq import heappush


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        h = []
        for n in nums:
            heappush(h, n)
            if len(h) > k:
                heappop(h)
        return h[0]