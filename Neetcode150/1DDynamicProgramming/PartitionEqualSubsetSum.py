from typing import *

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        t = sum(nums)
        if t % 2 == 1:
            return False
        memo = {}

        def helper(i, c):
            if c == 0:
                return True
            if i < 0:
                return False
            if (i, c) in memo.keys():
                return memo[(i, c)]
            
            memo[(i, c)] = helper(i-1, c) or helper(i-1, c-nums[i])
            return memo[(i, c)]
        
        return helper(n-1, t//2)

s = Solution()
print(s.canPartition([1,2,3,4,12]))