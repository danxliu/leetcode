from typing import *

class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1 or n == 2:
            return n

        i = 1
        j = 2
        
        for k in range(n-2):
            i, j = j, i+j
        return j


s = Solution()
print(s.climbStairs(3))