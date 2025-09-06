from typing import *

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums = sorted(nums)

        ans = []
        for i in range(n):
            target = -nums[i]
            j = i + 1
            k = n - 1

            if i > 0 and nums[i] == nums[i-1]:
                continue

            while(j < k):
                sm = nums[j] + nums[k]
                if sm == target:
                    ans.append([nums[i], nums[j], nums[k]])
                    j+=1
                    k-=1
                    while nums[j-1] == nums[j] and j < k:
                        j+=1
                elif sm < target:
                    j+=1
                elif sm > target:
                    k-=1
        return ans