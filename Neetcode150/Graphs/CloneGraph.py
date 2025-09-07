from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution:
    def cloneGraph(self, node: Optional[Node]) -> Optional[Node]:
        vis = {}
        def helper(node):
            if not node:
                return None
            if node in vis:
                return vis[node]
            
            new_node = Node()
            new_node.val = node.val
            vis[node] = new_node
            for neighbor in node.neighbors:
                new_neighbor = helper(neighbor)
                new_node.neighbors.append(new_neighbor)
            return new_node
        
        return helper(node)