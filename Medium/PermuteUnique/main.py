def permuteUnique(nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    if len(nums) == 0:
        return [[]]
    ans = []
    for i in range(len(nums)):
        for j in permuteUnique(nums[:i] + nums[i+1:]):
            temp = [nums[i]] + j
            if (not temp in ans):
                ans.append(temp)
    return ans


print(permuteUnique([1, 1, 2]))
