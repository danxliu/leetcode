from typing import *

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # optimal: in place
        n = len(nums)
        res = [1] * n
        prefix = 1
        
        for i in range(len(nums)):
            res[i] *= prefix
            prefix *= nums[i]
        
        suffix = 1
        for i in range(len(nums)-1, -1, -1):
            res[i] *= suffix
            suffix *= nums[i]

        return res

s = Solution()
print(s.productExceptSelf([-1,0,1,2,3]))