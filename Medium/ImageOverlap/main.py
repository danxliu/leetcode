from typing import List
from collections import defaultdict

class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        mp = defaultdict(int)
        n = len(img1)
        img1s = []
        img2s = []
        for i in range(n):
            for j in range(n):
                if img1[i][j]:
                    img1s.append((i, j))
                if img2[i][j]:
                    img2s.append((i, j))
        mx = 0
        for i in img1s:
            for j in img2s:
                delta = (i[0] - j[0], i[1] - j[1])
                mp[delta] += 1
                mx = max(mx, mp[delta])
        return mx

s = Solution()
img1 = [[0]]
img2 = [[0]]
print(s.largestOverlap(img1, img2))
