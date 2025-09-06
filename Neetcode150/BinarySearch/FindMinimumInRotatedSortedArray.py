from typing import *
import math

class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        l = 0
        r = n - 1

        while l < r:
            mid = (l + r) // 2
            print(l, r, mid)
            if nums[mid] < nums[r]:
                r = mid
            else:
                l = mid + 1
        return nums[l]

s = Solution()
print(s.findMin([3,4,5,6,1,2]))
