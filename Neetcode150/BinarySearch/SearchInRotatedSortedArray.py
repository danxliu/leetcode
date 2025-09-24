from typing import List
from bisect import bisect_left

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # find the point where the array was rotated
        n = len(nums)
        l = 0
        r = n-1
        
        while l < r:
            mid = (l + r) // 2
            if nums[mid] > nums[r]:
                l = mid + 1
            else:
                r = mid
        pivot = l
        left = bisect_left(nums, target, 0, pivot-1)
        right = bisect_left(nums, target, pivot, n-1)
        return left if left != n and nums[left] == target else right if right != n and nums[right] == target else -1

s = Solution()
print(s.search([4,5,6,7,0,1,2], 0))