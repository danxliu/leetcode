from typing import *
import heapq

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        
        pq = []
        ans = []
        for r in range(len(nums)):
            heapq.heappush(pq, (-nums[r], r))
            
            if r >= k-1:
                while pq[0][1] < (r - k + 1):
                    heapq.heappop(pq)
                ans.append(-pq[0][0])
        return ans

s = Solution()
print(s.maxSlidingWindow([1,2,1,0,4,2,6], 3))