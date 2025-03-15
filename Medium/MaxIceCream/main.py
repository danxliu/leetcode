class Solution(object):
    def maxIceCream(self, costs, coins):
        """
        :type costs: List[int]
        :type coins: int
        :rtype: int
        """
        costs.sort()
        ans = 0
        while len(costs) > 0 and coins > costs[0]:
            coins -= costs[0]
            ans += 1
            costs.pop(0)
        return ans
