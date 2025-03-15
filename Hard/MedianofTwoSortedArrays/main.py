def findMedianSortedArrays(nums1, nums2):
    """
    : type nums1: List[int]
    : type nums2: List[int]
    : rtype: float
    """
    arr = nums1 + nums2
    arr = sorted(arr)
    l = len(arr)
    if l % 2 == 0:
        return (arr[l//2 - 1] + arr[l//2])/2.0
    return arr[l//2]


print(findMedianSortedArrays([1, 3], [2]))
