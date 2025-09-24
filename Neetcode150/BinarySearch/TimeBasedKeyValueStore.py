class TimeMap:
    def __init__(self):
        self.mp = {}
    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.mp:
            self.mp[key] = []
        self.mp[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.mp or not self.mp[key]:
            return ""
        n = len(self.mp[key])
        l = 0
        r = n-1
        while l < r:
            mid = (l + r + 1) // 2
            if self.mp[key][mid][0] == timestamp:
                return self.mp[key][mid][1]
            elif self.mp[key][mid][0] < timestamp:
                l = mid
            else:
                r = mid - 1
        return "" if self.mp[key][l][0] > timestamp else self.mp[key][l][1]
