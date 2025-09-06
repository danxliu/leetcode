from typing import *

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        st = set()
        ans = 0
        l = 0
        

        for r in range(n):
            while s[r] in st:
                st.remove(s[l])
                l+=1
            st.add(s[r])
            ans = max(ans, r - l + 1)
        
        return ans

s = Solution()
print(s.lengthOfLongestSubstring('zxyzxyz'))