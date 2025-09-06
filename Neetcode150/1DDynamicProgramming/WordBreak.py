from typing import *

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        memo = {}
        
        def helper(s):
            if len(s) == 0:
                return True

            if s in memo.keys():
                return memo[s]
            
            ans = False
            for str in wordDict:
                n = len(str)
                if s[:n] == str:
                    ans = ans or helper(s[n:])
                    if ans:
                        break
            memo[s] = ans
            return ans

        return helper(s)

s = Solution()
print(s.wordBreak("catsincars", ["cats","cat","sin","in","car"]))