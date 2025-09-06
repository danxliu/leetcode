from typing import *

class Solution:
    def numDistinct(self, s: str, t: str) -> int:

        memo = {}

        def helper(i, j):
            if j == len(t):
                return 1
            
            if i >= len(s):
                return 0

            if (i, j) in memo:
                return memo[(i, j)]
            
            memo[(i, j)]= helper(i+1, j)
            if s[i] == t[j]:
                memo[(i, j)]+= helper(i+1, j+1)
            return memo[(i, j)]

        return helper(0, 0)
    

s = Solution()

print(s.numDistinct("xxyxy", "xy"))