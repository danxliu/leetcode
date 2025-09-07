from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        cur = []
        ans = []
        candidates.sort()

        def dfs(i):
            if sum(cur) == target:
                ans.append(cur.copy())
                return
            if sum(cur) > target or i>=len(candidates):
                return
            
            cur.append(candidates[i])
            dfs(i+1)
            cur.pop()
            while i+1 < len(candidates) and candidates[i] == candidates[i+1]:
                i+=1
            dfs(i+1)
        dfs(0)
        return ans
    
s = Solution()
print(s.combinationSum2([10,1,2,7,6,1,5], 8))