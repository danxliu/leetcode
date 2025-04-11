class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution(object):
    def __init__(self):
        self.mp = {}

    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        if not node:
            return None

        if (node.val in self.mp):
            return self.mp[node.val]

        new_node = Node(node.val)

        self.mp[node.val] = new_node
        for neighbor in node.neighbors:
            new_node.neighbors.append(self.cloneGraph(neighbor))
        return new_node