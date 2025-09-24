class Solution:
    def kthCharacter(self, k: int) -> str:
        def helper(s):
            r = ""
            for c in s:
                r += chr((ord(c) - ord('a') + 1) % 26 + ord('a'))
            return r
        word = 'a'
        for _ in range(k):
            word += helper(word)
            if len(word) > (k-1):
                return word[k-1]
        return word[k-1]
