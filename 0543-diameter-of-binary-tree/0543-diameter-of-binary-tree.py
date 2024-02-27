maxDiameter = 0

class Solution:
    def getDepth(self, root: Optional[TreeNode]) -> int:
        global maxDiameter
        if not root.left and not root.right:
            return 0
        leftSubtreeDepth = self.getDepth(root.left) + 1 if root.left else 0
        rightSubtreeDepth = self.getDepth(root.right) + 1 if root.right else 0
        maxDiameter = max(maxDiameter, leftSubtreeDepth + rightSubtreeDepth)
        return max(leftSubtreeDepth, rightSubtreeDepth)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        global maxDiameter
        maxDiameter = 0
        return max(self.getDepth(root), maxDiameter)