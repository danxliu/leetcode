class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        for i in t:
            if (len(s) == 0):
                return False
            if (s[0] == i):
                s = s[1:]
        return len(s) == 0


s = Solution()
print(s.isSubsequence("", "ahbgdc"))
