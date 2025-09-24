class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        hand.sort()
        mp = defaultdict(int)
        for c in hand:
            mp[c]+=1
        
        for c in hand:
            if not mp[c]:
                continue
            for i in range(c, c+groupSize):
                if i not in mp or mp[i] == 0:
                    return False
                mp[i] -= 1
        return True