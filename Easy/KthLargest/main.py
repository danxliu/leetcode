from bisect import bisect_left


class KthLargest(object):

    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """
        self.k = k
        nums.sort()
        self.nums = nums

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """
        self.nums.insert(bisect_left(self.nums, val), val)
        return self.nums[len(self.nums) - self.k]
