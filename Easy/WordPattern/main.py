class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        mp = {}
        s = s.split(" ")
        if len(s) != len(pattern):
            return False
        for i in range(len(pattern)):
            if not pattern[i] in mp:
                mp[pattern[i]] = s[i]
            else:
                if mp[pattern[i]] != s[i]:
                    return False
            for j in mp.items():
                if j[1] == s[i] and j[0] != pattern[i]:
                    return False
        return True

s = Solution()
print(s.wordPattern("aaa", "aa aa aa"))