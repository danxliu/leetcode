from collections import defaultdict

class Solution:
    def maxFreqSum(self, s: str) -> int:
        v = defaultdict(int)
        c = defaultdict(int)

        for i in s:
            if i in "aeiou":
                v[i]+=1
            else:
                c[i]+=1
        bv = 0
        bc = 0
        for freq in v.values():
            bv = max(bv, freq)
        for freq in c.values():
            bc = max(bc, freq)
        return bc + bv