class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.maxSum = float('-inf')

    def maxPathSum(self, root):
        self.dfs(root)
        return self.maxSum

    def dfs(self, node):
        if not node:
            return 0
        left = max(0, self.dfs(node.left))
        right = max(0, self.dfs(node.right))
        self.maxSum = max(self.maxSum, left + right + node.val)
        return node.val + max(left, right)

# Test case
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
solution = Solution()
result = solution.maxPathSum(root)  # Output: 6 (2 -> 1 -> 3)
print(result)
