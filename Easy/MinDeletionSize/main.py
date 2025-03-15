class Solution(object):
    def minDeletionSize(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        ans = 0
        for i in range(len(strs[0])):
            cs = ""
            for j in strs:
                cs += j[i]
            if sorted(cs) != list(cs):
                ans += 1
        return ans


s = Solution()
print(s.minDeletionSize(["abc", "bce", "cae"]))
