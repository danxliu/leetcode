from typing import *
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        ans = 0

        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j]+1)
            ans = max(ans, dp[i])
        
        return ans

s = Solution()
print(s.lengthOfLIS([0,3,1,3,2,3]))