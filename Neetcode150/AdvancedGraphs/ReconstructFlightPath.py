from collections import defaultdict
from typing import List

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adjmat = defaultdict(list)
        for ticket in tickets.sort()[::-1]:
            adjmat[ticket[0]].append(ticket[1])
        
        ans = ["JFK"]
        # Backtracking
        def recurse(curAirport):
            while adjmat[curAirport]:
                nextAirport = adjmat[curAirport].pop()
                recurse(nextAirport)
            ans.append(nextAirport)

        recurse("JFK")
        return ans[::-1]