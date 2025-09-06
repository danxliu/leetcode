from typing import *

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        memo = {}

        def helper(i, buying):
            if (i >= len(prices)):
                return 0
            
            if (i, buying) in memo.keys():
                return memo[(i, buying)]
            
            memo[(i, buying)] = max(helper(i+1, buying), helper(i+1, not buying) - prices[i] if buying else helper(i+2, not buying) + prices[i])
            return memo[(i, buying)]
        return helper(0, True)

s = Solution()
print(s.maxProfit([1]))