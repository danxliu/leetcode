class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        mx = 0
        cmx = 0
        cmn = 0
        for i in prices:
            if i < cmn:
                cmn = i
                cmx = i
            elif i > cmx:
                cmx = i
                mx = max(mx, cmx-cmn)
        return mx
