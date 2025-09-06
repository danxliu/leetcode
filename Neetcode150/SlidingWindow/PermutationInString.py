from typing import *

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        mp1 = {}
        n = len(s1)
        for c in s1:
            mp1[c] = mp1.get(c, 0) + 1
        mp2 = {}

        if len(s1) > len(s2):
            return False
        
        for i in range(0, n):
            mp2[s2[i]] = mp2.get(s2[i], 0) + 1
            
        l = 0
        r = n
        while r < len(s2):
            if mp1 == mp2:
                return True
            mp2[s2[l]] -= 1
            if mp2[s2[l]] == 0:
                mp2.pop(s2[l])
            
            mp2[s2[r]] = mp2.get(s2[r], 0) + 1
            
            l+=1
            r+=1
        return mp1 == mp2

s = Solution()
print(s.checkInclusion("adc", "dcda"))