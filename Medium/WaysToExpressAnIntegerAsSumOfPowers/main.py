class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        mod = 10**9+7

        memo = {}
        def helper(i, j):
            if (i, j) in memo:
                return memo[(i, j)]
            
            if i == 0:
                return 1
            
            if i < 0 or j < 0:
                return 0
            
            memo[(i, j)] = (helper(i, j-1) + helper(i-(j**x), j-1)) % mod
            return memo[(i, j)]
        
        return helper(n, n)
            
