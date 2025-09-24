class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        cursum = 0
        ans = 0
        bits = k.bit_length()

        for i, c in enumerate(s[::-1]):
            if c == '1' and i < bits and cursum + (1 << i) <= k:
                cursum+=(1<<i)
                ans+=1
            elif c == '0':
                ans+=1
        return ans
