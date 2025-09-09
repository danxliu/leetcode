from typing import List

class Solution:
    def totalStrength(self, strength: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(strength)
        st = []
        left = [-1] * n
        right = [n] * n
        for i in range(n):
            while st and strength[st[-1]] >= strength[i]:
                st.pop()
            left[i] = -1 if not st else st[-1]
            st.append(i)
        st.clear()
        for i in range(n-1, -1, -1):
            while st and strength[st[-1]] > strength[i]:
                st.pop()
            right[i] = n if not st else st[-1]
            st.append(i)
        
        # Prefix sums
        pre = [0] * (n+1)
        for i in range(1, n+1):
            pre[i] = pre[i-1] + strength[i-1]
        ppre = [0] * (n+2)
        for i in range(2, n+2):
            ppre[i] = ppre[i-1] + pre[i-1]

        ans = 0
        for i in range(n):
            l = left[i] + 1
            r = right[i] - 1
            cntl = (i - l + 1)
            cntr = (r - i + 1)
            c = ((ppre[r+2] - ppre[i+1]) * cntl - (ppre[i+1] - ppre[l]) * cntr) * strength[i]
            c %= MOD
            ans += c
            ans %= MOD
        return ans

s = Solution()
print(s.totalStrength([1, 3, 1, 2]))