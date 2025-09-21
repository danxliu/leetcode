from collections import defaultdict

class Router:
    def __init__(self, memoryLimit: int):
        self.q = deque()
        self.memoryLimit = memoryLimit
        self.cache = defaultdict(int)
        self.entries = defaultdict(deque)

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        packet = (source, destination, timestamp)
        if packet in self.cache:
            return False
        
        self.q.append(packet)
        self.cache[packet] += 1
        self.entries[destination].append(timestamp)

        if len(self.q) > self.memoryLimit:
            evict = self.q.popleft()
            self.cache[evict] -= 1
            if self.cache[evict] == 0:
                del self.cache[evict]
                self.entries[evict[1]].popleft()
        return True

    def forwardPacket(self) -> list[int]:
        if not self.q:
            return []
        evict = self.q.popleft()
        self.cache[evict] -= 1
        if self.cache[evict] == 0:
            del self.cache[evict]
            self.entries[evict[1]].popleft()
        return list(evict)


    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        left = bisect_left(self.entries[destination], startTime)
        right = bisect_right(self.entries[destination], endTime)
        return right - left
