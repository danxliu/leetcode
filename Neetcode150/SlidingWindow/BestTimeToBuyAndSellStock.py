from typing import *

class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        ans = 0
        l = 10e9
        for price in prices:
            l = min(price, l)
            ans = max(price - l, ans)
        return ans
                 
s = Solution()
print(s.maxProfit([10,1,5,6,7,1]))