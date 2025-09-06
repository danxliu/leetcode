from typing import *

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        memo = {}
        def helper(i, j):
            if j == len(p):
                return i == len(s)

            if (i, j) in memo:
                return memo[(i, j)]
            
            if j + 1 < len(p) and p[j+1] == "*":
                memo[(i, j)] = helper(i, j+2) or ((i < len(s) and (p[j]==s[i] or p[j]=='.')) and helper(i+1, j))
            else:
                memo[(i, j)] = ((i < len(s) and (p[j]==s[i] or p[j]=='.')) and helper(i+1, j+1))
            
            return memo[(i, j)]
    
        return helper(0, 0)
    
s = Solution()
print(s.isMatch("xyz", "..z*"))

            