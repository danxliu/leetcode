def maxSubArray(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    mn = min(nums)
    mx = mn
    cur = 0
    for i in nums:
        cur += i
        if (cur < mn):
            cur = i
        mx = max(cur, mx)
    return mx


print(maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))
