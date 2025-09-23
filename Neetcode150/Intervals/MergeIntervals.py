from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans = []
        intervals.sort()
        curInterval = intervals[0]

        for i in range(1, len(intervals)):
            if curInterval[1] < intervals[i][0]:
                ans.append(curInterval)
                curInterval = intervals[i]
            else:
                curInterval = [min(curInterval[0], intervals[i][0]), max(curInterval[1], intervals[i][1])]
        ans.append(curInterval)
        return ans