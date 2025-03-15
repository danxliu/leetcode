class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        mp = {}
        for i in s:
            if i in mp:
                mp[i] += 1
            else:
                mp[i] = 1
        used = False
        ans = 0
        for i in mp.values():
            if i % 2 == 1:
                if not used:
                    ans += 1
                    used = True
            ans += ((i//2)*2)
        return ans


s = Solution()
print(s.longestPalindrome("abccccdd"))
