from typing import *

class Solution:
    def numDecodings(self, s: str) -> int:
        
        n = len(s)
        memo = {}
        mp = [str(i) for i in range(1, 27)]

        def helper(s):
            if len(s) == 0:
                return 1
            
            if s in memo.keys():
                return memo[s]

            cur=0
            if s[:1] in mp:
                cur += helper(s[1:])
            if len(s) >= 2 and s[:2] in mp:
                cur += helper(s[2:])
            memo[s] = cur
            return memo[s]
        ans = helper(s)
        return ans

s = Solution()
print(s.numDecodings("01"))