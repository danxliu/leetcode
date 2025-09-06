from typing import *


class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        # dp[i][j] = true if s[i:j+1] is a palindrome
        # dp[i][j] = s[i] == s[j] && dp[i+1][j-1]

        ans = 1
        st, ed = 0, 0

        # a single char is a palindrome
        for i in range(n):
            dp[i][i] = True

        for i in range(n-1):
            dp[i][i+1] = (s[i] == s[i+1])
            if dp[i][i+1]:
                st, ed = i, i+1

        for l in range(2, n):
            for i in range(n-l):
                # l: length
                # i: start
                dp[i][i+l] = (s[i] == s[i+l]) and dp[i+1][i+l-1]
                print(dp[i][i+l])
                if dp[i][i+l] and l > ed-st:
                    st, ed = i, i+l
        return s[st:ed+1]


s = Solution()
print(s.longestPalindrome("ababd"))
