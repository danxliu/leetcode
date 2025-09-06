from typing import *

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set()
        for num in nums:
            s.add(num)
        
        ans = 0
        for num in s:
            l = 1
            while (num + l in s):
                l+=1
            ans = max(l, ans)
        return ans