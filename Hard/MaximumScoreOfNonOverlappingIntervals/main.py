from bisect import bisect_left

class Solution(object):
    def maximumWeight(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[int]
        """
        n = len(intervals)
        intervals = [[l, r, w, idx] for idx, (l, r, w) in enumerate(intervals)]
        intervals.sort(key = lambda a: (a[1], -a[2]))
        print(intervals)
        p = [bisect_left(intervals, intervals[i][0], key= lambda a: a[1]) - 1 for i in range(n)] # Let p[i] = j be the first interval where interval[j].r < interval[i].l
        
        memo = {}
        def dp(i, num):
            # Max weight from intervals [0, i] with n intervals
            if num == 0 or i < 0:
                return (0, ())
            if (i, num) in memo:
                return memo[(i, num)]

            cont_amt, cont_indices = dp(i-1, num)
            take_amt, prev_indices = dp(p[i], num - 1)
            take_amt += intervals[i][2]
            take_indices = tuple(sorted(prev_indices + (intervals[i][3],)))
            if take_amt > cont_amt:
                best = (take_amt, take_indices)
            elif take_amt < cont_amt:
                best = (cont_amt, cont_indices)
            else:
                best = (take_amt, min(take_indices, cont_indices))
            memo[(i, num)] = best
            return best
        return list(dp(n-1, 4)[1])

s = Solution()
intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]
s.maximumWeight(intervals)
        
