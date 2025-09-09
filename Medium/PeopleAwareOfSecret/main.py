class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        MOD = 10**9+7
        dp = [[0] * forget for _ in range(n+2)]

        dp[1][0] = 1
        for i in range(2, n+1):
            dp[i][0] = sum(dp[i-1][delay-1:forget-1]) % MOD
            for j in range(1, forget):
                dp[i][j] = dp[i-1][j-1] % MOD
        return sum(dp[n]) % MOD
