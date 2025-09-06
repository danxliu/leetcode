class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        st1 = {}
        st2 = {}
        
        for c in s:
            st1[c] = st1.get(c, 0) + 1

        for c in t:
            st2[c] = st2.get(c, 0) + 1
        
        return st1 == st2