from typing import *

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        memo = {}
        
        def helper(amount, i):
            if i == -1 and amount == target:
                return 1
            
            if i < 0:
                return 0
            
            if (amount, i) in memo.keys():
                return memo[(amount, i)]
            
            memo[(amount, i)] = helper(amount - nums[i], i-1) + helper(amount + nums[i], i-1)
            return memo[(amount, i)]
        
        return helper(0, len(nums) - 1)

s = Solution()
print(s.findTargetSumWays([2, 2, 2], 2))