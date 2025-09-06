from typing import *

class Solution:
    
    def generateParenthesis(self, n: int) -> List[str]:
        st = []
        ans = []

        def helper(open, closed):
            if open == n and closed == n:
                ans.append("".join(st))
                return
            
            if open < n:
                st.append('(')
                helper(open+1, closed)
                st.pop()
            
            if closed < open:
                st.append(')')
                helper(open, closed + 1)
                st.pop()
        helper(0, 0)
        return ans