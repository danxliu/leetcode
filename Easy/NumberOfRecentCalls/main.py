class RecentCounter:

    def __init__(self):
        self.pings = []

    def ping(self, t: int) -> int:
        count = 0
        self.pings.append(t)
        for ping in self.pings:
            if (ping >= t - 3000 and ping <= t):
                count+=1
        if count == 0:
            return None
        return count
