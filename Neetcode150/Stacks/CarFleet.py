from typing import *


class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cl = []
        for p, s in zip(position, speed):
            cl.append((p, s))
        cl.sort(reverse=True)
        
        st = []
        for cp, cs in cl:
            st.append((target - cp) / cs)
            if len(st) >= 2 and st[-1] <= st[-2]:
                st.pop()
        return len(st)

s = Solution()
print(s.carFleet(10, [1, 4], [3, 2]))
