class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def helper(root, val):
            if not root:
                return 0
            ans = 0
            if root.val >= val:
                ans += 1
            nextVal = max(root.val, val)
            ans += helper(root.left, nextVal)
            ans += helper(root.right, nextVal)
            return ans
        return helper(root, float("-inf"))