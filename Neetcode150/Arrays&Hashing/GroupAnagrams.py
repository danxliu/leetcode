from typing import *

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # mapping from string to frequency array
        mp = {}
        for str in strs:
            carr = [0] * 26
            for c in str:
                carr[ord(c) - ord('a')]+=1
            t = tuple(carr)
            mp[t] = mp.get(t, [])
            mp[t].append(str)
        
        res = []
        for l in mp.values():
            res.append(l)
        return res
        

sol = Solution()
sol.groupAnagrams(["act","pots","tops","cat","stop","hat"])