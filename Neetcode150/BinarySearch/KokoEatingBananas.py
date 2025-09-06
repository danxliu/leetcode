from typing import *
import math

class Solution:
    def helper(self, piles, h, k):
        i = 0
        for pile in piles:
            i += math.ceil(pile / k)
        print(i)
        return (i <= h)

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)

        while l < r:
            mid = math.floor((l + r) / 2)
            if self.helper(piles, h, mid):
                r = mid
            else:
                l = mid + 1
        return l

s = Solution()
print(s.minEatingSpeed([25, 10, 23, 4], 4))
