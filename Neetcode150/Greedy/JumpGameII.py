from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, 0
        ans = 0

        while r < n-1:
            nr = max([i + nums[i] for i in range(l, r + 1)])
            l = r + 1
            r = nr
            ans += 1
        return ans