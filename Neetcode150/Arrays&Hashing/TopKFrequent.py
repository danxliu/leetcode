from typing import *
import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        buckets = [[] for i in range(len(nums) + 1)]
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        for n, f in freq.items():
            buckets[f].append(n)
            
        res = []
        for i in range(len(buckets) - 1, 0, -1):
            for num in buckets[i]:
                res.append(num)
                if len(res) == k:
                    return res
            

sol = Solution()
print(sol.topkfrequent([1, 2, 2, 3, 3, 3], 2))
        