from typing import *

class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        ans = 0

        def palindrome(i, j):
            t = 0
            while i >= 0 and j < n and s[i] == s[j]:
                i-=1
                j+=1
                t+=1
            return t

        for i in range(n):
            ans += palindrome(i, i)
            ans += palindrome(i, i+1)
        return ans

s = Solution()
print(s.countSubstrings("aaa"))