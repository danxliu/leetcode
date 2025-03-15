class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def recurse(s, dots, ans):
            if dots == 3:
                if s and (s[0] != '0' or len(s) == 1) and int(s) <= 255:
                    return [ans+s]
                return []
            res = []
            if (not s):
                return []
            if (s[0] == '0'):
                res.extend(recurse(s[1:], dots+1, ans+s[:1]+'.'))
            else:
                res.extend(recurse(s[1:], dots+1, ans+s[:1]+'.'))
                res.extend(recurse(s[2:], dots+1, ans+s[:2]+'.'))
                if (int(s[:3]) <= 255):
                    res.extend(recurse(s[3:], dots+1, ans+s[:3]+'.'))
            return res
        return recurse(s, 0, "")


s = Solution()
print(s.restoreIpAddresses("0000"))
