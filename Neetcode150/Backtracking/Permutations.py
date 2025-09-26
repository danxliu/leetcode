class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        if len(nums) == 1:
            return [[nums[0]]]
        
        ans = []
        for i in range(len(nums)):
            for p in self.permute(nums[:i] + nums[i+1:]):
                ans.append([nums[i]] + p)
        return ans