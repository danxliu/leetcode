from typing import *


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        vis = {}
        
        for i in range(len(nums)):
            num = nums[i]
            rem = target-num
            if (rem) in vis:
                return [vis[rem], i]
            vis[num] = i
        
        return None

sol = Solution()
print(sol.twoSum([3, 4, 5, 6], 7))

