class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        arr = [0] * (n+1)
        for query in queries:
            arr[query[0]]+=1
            arr[query[1]+1]-=1
        cur = 0
        for i in range(n):
            cur += arr[i]
            if cur < nums[i]:
                return False
        return True
