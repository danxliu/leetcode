from typing import *

class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0, len(heights) - 1

        mx = min(heights[l], heights[r]) * (r-l)
        while (l < r):
            if heights[l] < heights[r]:
                l+=1
            elif heights[l] > heights[r]:
                r-=1
            else:
                l+=1
                r-=1
            mx = max(mx, min(heights[l], heights[r]) * (r-l))
        return mx

s = Solution()
print(s.maxArea([1,7,2,5,4,7,3,6]))