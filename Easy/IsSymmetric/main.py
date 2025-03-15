# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def helper(self, left, right):
        if (left == None or right == None):
            return left == None and right == None
        if (left.val != right.val):
            return False
        return self.helper(left.left, right.right) and self.helper(left.right, right.left)

    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True
        else:
            return self.helper(root.left, root.right)
