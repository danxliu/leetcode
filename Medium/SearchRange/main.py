def searchRange(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    # binary search for lower bound
    ans = [-1, -1]
    low = 0
    high = len(nums)-1
    mid = 0
    while low < high:
        mid = (low + high)//2
        if nums[mid] >= target:
            high = mid
        else:
            low = mid + 1
    if (low == high and nums[low] == target):
        ans[0] = low

    low = 0
    high = len(nums)-1
    while low < high:
        mid = (low + high)//2 + 1
        if (nums[mid] <= target):
            low = mid
        else:
            high = mid - 1
    if (low == high and nums[low] == target):
        ans[1] = low

    return ans


print(searchRange([2, 2], 2))
