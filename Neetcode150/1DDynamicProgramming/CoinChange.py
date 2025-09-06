from typing import *

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:

        dp = [10e9] * (amount+1)
        dp[0] = 0
        
        for i in range(1, amount+1):
            for coin in coins:
                if i - coin >= 0:
                    dp[i] = min(dp[i], dp[i-coin]+1)
        if dp[amount] == 10e9:
            return -1
        return dp[amount]
        

s = Solution()
print(s.coinChange([1], 0))