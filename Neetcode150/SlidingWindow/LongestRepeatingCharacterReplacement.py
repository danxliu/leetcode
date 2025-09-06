from typing import *

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        mp = {}
        
        mf = 0
        l = 0
        ans = 0
        for r in range(n):
            mp[s[r]] = mp.get(s[r], 0) + 1
            mf = max(mf, mp.get(s[r]))

            while (r - l + 1) - mf > k:
                mp[s[l]] -= 1
                l+=1
            ans = max(ans, r - l + 1)

        return ans

s = Solution()
print(s.characterReplacement("AAABABB", 1))