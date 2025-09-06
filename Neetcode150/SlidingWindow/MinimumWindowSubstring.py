from typing import *


class Solution:

    # constant time check
    def check(self, mpt, mps):
        for c, n in mpt.items():
            ns = mps.get(c)
            if not ns or ns < n:
                return False
        return True

    def minWindow(self, s: str, t: str) -> str:

        if len(s) < len(t):
            return ""

        mpt = {}
        for c in t:
            mpt[c] = mpt.get(c, 0) + 1

        l = 0
        r = 0
        mps = {}

        ans = None
        need, cur = len(mpt), 0

        for r in range(len(s)):
            # Find window including t by expanding r
            mps[s[r]] = mps.get(s[r], 0) + 1

            if s[r] in mpt and mps[s[r]] == mpt[s[r]]:
                cur += 1

            # Restrict left and update answer
            while cur == need:
                if not ans or (r-l+1) < (ans[1] - ans[0] + 1):
                    ans = (l, r)

                mps[s[l]] -= 1
                if s[l] in mpt and mps[s[l]] < mpt[s[l]]:
                    cur -= 1
                l += 1
        if not ans:
            return ""
        return s[ans[0]:ans[1]+1]


s = Solution()
print(s.minWindow("ADOBECODEBANC", "ABC"))

# OUZODYXAZV XYZ

# find window including t: OUZODYX
# restrict left and update answer: ZODYX
# restrict left more (add one and continue restricting): YX
# find window including t: YXAZ
# restrict left and update answer: YXAZ
# restrict left more (add one and continue restricting): XAZV -> reach end without

# We need to check if substring contains t efficiently O(1) time somehow
# This is fine: number of uppercase/lowercase english letters are constant
# We can use a frequency map to check
