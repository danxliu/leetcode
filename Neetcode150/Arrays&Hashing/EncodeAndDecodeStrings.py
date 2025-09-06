from typing import *

class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res += str(len(s))
            res += "."
            res += s
        return res

    def decode(self, s: str) -> List[str]:
        i = 0
        res = []
        while(i < len(s)):
            num = ""
            while(s[i] != '.'):
                num += s[i]
                i+=1
            res.append(s[i+1:i+int(num)+1])
            i += int(num)+1
        return res

s = Solution()
es = s.encode(["we", "say", ":", "yes"])
print(s.decode(es))