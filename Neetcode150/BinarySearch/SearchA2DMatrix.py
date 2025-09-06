from typing import *
import math

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])

        # find the proper row
        l = 0
        r = n-1
        while l <= r:
            mid = math.floor((l + r)/2)
            if matrix[mid][0] == target:
                return True
            elif matrix[mid][0] < target:
                l = mid + 1
            elif matrix[mid][0] > target:
                r = mid - 1

        i = r
        l = 0
        r = m-1
        while l <= r:
            mid = math.floor((l + r) / 2)
            if matrix[i][mid] == target:
                return True
            elif matrix[i][mid] < target:
                l = mid + 1
            elif matrix[i][mid] > target:
                r = mid - 1
        return False

s = Solution()
print(s.searchMatrix([[1,2,4,8],[10,11,12,13],[14,20,30,40]], 15))
