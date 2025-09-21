from typing import List

class Solution:
    def canJump(self, nums: list[int]) -> bool:
        n = len(nums)
        curpos = n-1
        for i in range(n-2, -1, -1):
            if nums[i] + i >= curpos:
                curpos = i
        return curpos == 0
