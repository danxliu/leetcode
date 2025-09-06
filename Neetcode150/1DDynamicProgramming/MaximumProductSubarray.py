from typing import *

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        mn, mp = 1, 1
        ans = nums[0]

        for num in nums:
            mn, mp = min(num * mp, num * mn, num), max(num * mp, num * mn, num)
            ans = max(ans, mp)
        return ans
