from typing import *

class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        
        omp = {
            '(': ')',
            '[': ']',
            '{': '}'
        }
        cmp = {
            ')': '(',
            ']': '[',
            '}': '{'
        }
        
        for c in s:
            if c in omp.keys():
                st.append(c)
            elif c in cmp.keys():
                if len(st) == 0 or st[-1] != cmp[c]:
                    return False
                st.pop()
        return len(st) == 0

s = Solution()
print(s.isValid("[(])"))
                