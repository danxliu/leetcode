from typing import *

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:

        if len(s1) + len(s2) != len(s3):
            return False

        memo = {}

        def helper(i, j):
            k = i+j
            if (i == len(s1) and s2[j:] != s3[k:]):
                return False
            
            if (j == len(s2) and s1[i:] != s3[k:]):
                return False
            
            if i == len(s1) and j == len(s2):
                return True
            
            if (i, j) in memo:
                return memo[(i, j)]
            
            memo[(i, j)] = False
            
            if i < len(s1) and s1[i] == s3[k]:
                memo[(i, j)] = memo[(i, j)] or helper(i+1, j)

            if j < len(s2) and s2[j] == s3[k]:
                memo[(i, j)] = memo[(i, j)] or helper(i, j+1)
            
            return memo[(i, j)]
        return helper(0, 0)

s = Solution()

print(s.isInterleave("abc", "xyz", "abxycz"))

            
