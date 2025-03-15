class Solution(object):
    def maximumBags(self, capacity, rocks, additionalRocks):
        """
        :type capacity: List[int]
        :type rocks: List[int]
        :type additionalRocks: int
        :rtype: int
        """
        left = []
        for i in range(len(capacity)):
            left.append(capacity[i] - rocks[i])
        left.sort()
        ans = 0
        for i in range(len(left)):
            if left[i]:
                if additionalRocks >= left[i]:
                    additionalRocks -= left[i]
                    left[i] = 0
                else:
                    return ans
            if left[i] == 0:
                ans += 1
        return ans
