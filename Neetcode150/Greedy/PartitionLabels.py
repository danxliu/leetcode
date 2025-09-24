class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        
        mp = {}
        for i, c in enumerate(s[::-1]):
            if c not in mp:
                mp[c] = len(s) - i - 1

        ans = []
        i = 0
        while i < len(s):
            e = mp[s[i]]
            j = i
            while j <= e:
                e = max(e, mp[s[j]])
                j+=1
            ans.append(j - i)
            i = j
        return ans