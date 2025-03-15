# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if not root.children:
            return [root.val]
        res = []
        for i in root.children:
            res.extend(self.preorder(i))
        return [root.val] + res
