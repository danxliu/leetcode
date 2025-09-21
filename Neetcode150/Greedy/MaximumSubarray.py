from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        cur = 0
        ans = nums[0]
        for num in nums:
            cur = max(cur, 0)
            cur += num
            ans = max(ans, cur)
        return ans