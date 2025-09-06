from typing import *

class Solution:
    def maxCoins(self, nums: List[int]) -> int:

        memo = {}
        nums = [1] + nums + [1]
        n = len(nums)

        def helper(l, r):
            if (l == r):
                return nums[l-1] * nums[l] * nums[r+1]
        
            if (l, r) in memo:
                return memo[(l, r)]
            
            memo[(l, r)] = 0
            for i in range(l, r+1):
                # Pop index i last
                memo[(l, r)] = max(memo[(l, r)], helper(l, i-1) + helper(i+1, r) + nums[i] * nums[l-1] * nums[r+1])
            return memo[(l, r)]

        return helper(1, n - 2)

s = Solution()
print(s.maxCoins([4, 2, 3, 7]))