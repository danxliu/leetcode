from typing import List
import heapq


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adjmat = {}
        for i in range(1, n+1):
            adjmat[i] = []
        for time in times:
            ui = time[0]
            vi = time[1]
            ti = time[2]
            adjmat[ui].append((vi, ti))
        

        q = []
        heapq.heappush(q, (0, k))
        bestTimes = {}
        bestTimes[k] = 0

        while len(q) > 0:
            curTime, curNode = heapq.heappop(q)
            for newNode, newTime in adjmat[curNode]:
                if newNode in bestTimes and bestTimes[newNode] <= newTime + curTime:
                    continue
                bestTimes[newNode] = newTime+curTime
                heapq.heappush(q, (curTime+newTime, newNode))
        
        ans = 0
        for i in range(1, n+1):
            if i not in bestTimes:
                return -1
            ans = max(ans, bestTimes[i])
        return ans