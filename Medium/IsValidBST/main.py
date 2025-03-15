# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        pot = []

        def dfs(r):
            if not r:
                return True
            pot.append(r)
            dfs(r.left)
            dfs(r.right)
        print(pot)
        return pot == sorted(set(pot))
