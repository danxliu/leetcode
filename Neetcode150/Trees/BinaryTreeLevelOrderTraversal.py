class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        ans = []
        curLevel = [root]
        nextLevel = []
        while curLevel:
            ans.append([node.val for node in curLevel if node])
            for node in curLevel:
                if node.left:
                    nextLevel.append(node.left)
                if node.right:
                    nextLevel.append(node.right)
            curLevel = nextLevel
            nextLevel = []
        return ans