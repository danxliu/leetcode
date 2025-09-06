class MinStack:

    def __init__(self):
        self.st = []
        self.mst = []

    def push(self, val: int) -> None:
        self.st.append(val)
        if self.mst:
            self.mst.append(min(val, self.mst[-1]))
        else:
            self.mst.append(val)

    def pop(self) -> None:
        self.st.pop()
        self.mst.pop()

    def top(self) -> int:
        return self.st[-1]

    def getMin(self) -> int:
        return self.mst[-1]
