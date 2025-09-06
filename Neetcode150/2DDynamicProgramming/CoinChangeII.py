from typing import *

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        coins.sort(reverse=True)
        memo = {}

        def helper(amount, i):
            if amount == 0:
                return 1
            if amount < 0:
                return 0
            if i < 0:
                return 0
            
            if (amount, i) in memo.keys():
                return memo[(amount, i)]
            
            memo[(amount, i)] = helper(amount - coins[i], i) + helper(amount, i-1)
            return memo[(amount, i)]

        return helper(amount, len(coins) - 1)

s = Solution()
print(s.change(4, [1, 2, 3]))
            