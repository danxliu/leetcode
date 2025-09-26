class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def valid(root, mn, mx):
            if not root:
                return True
            if not (mn < root.val < mx):
                return False
            return valid(root.left, mn, root.val) and valid(root.right, root.val, mx)
        return valid(root, float("-inf"), float("inf"))