from typing import List

class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:

        cur = []
        ans = []

        def dfs(i):
            if sum(cur) == target:
                ans.append(cur.copy())
                return
            if sum(cur) > target or i>=len(nums):
                return
            
            cur.append(nums[i])
            dfs(i)
            cur.pop()
            dfs(i+1)
        dfs(0)
        return ans

s = Solution()
print(s.combinationSum([3, 4, 5], 16))