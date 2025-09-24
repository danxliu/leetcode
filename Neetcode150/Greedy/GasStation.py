class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total = (sum(gas) - sum(cost))
        if total < 0:
            return -1
        n = len(gas)
        cur = 0
        ans = 0
        for i in range(n):
            cur += (gas[i] - cost[i])
            if cur < 0:
                cur = 0
                ans = i+1
        return ans