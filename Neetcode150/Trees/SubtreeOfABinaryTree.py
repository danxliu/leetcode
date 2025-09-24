class Solution:
    def isEqual(self, a, b):
        if not a and not b:
            return True
        if (not a and b) or (not b and a):
            return False
        return a.val == b.val and self.isEqual(a.left, b.left) and self.isEqual(a.right, b.right)
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not subRoot:
            return True
        if not root:
            return False
        
        return self.isEqual(root, subRoot) or self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)