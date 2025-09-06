from typing import *

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        ans = [0] * n
        
        hist = []
        for i in range(n):
            cur = temperatures[i]
            while hist and cur > hist[-1][0]:
                _, j = hist.pop()
                ans[j] = i - j
            
            hist.append((cur, i))
        return ans

s = Solution()
print(s.dailyTemperatures([30,38,30,36,35,40,28]))