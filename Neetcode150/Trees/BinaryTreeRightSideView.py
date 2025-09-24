class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []

        ans = []
        curLevel = [root]
        nextLevel = []
        while curLevel:
            ans.append(curLevel[-1].val)
            for node in curLevel:
                if node.left:
                    nextLevel.append(node.left)
                if node.right:
                    nextLevel.append(node.right)
            curLevel = nextLevel
            nextLevel = []
        return ans