def permute(nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    if len(nums) == 0:
        return [[]]
    ans = []
    for i in range(len(nums)):
        for j in permute(nums[:i] + nums[i+1:]):
            ans.append([nums[i]] + j)
    return ans

print(permute([1, 2, 3]))