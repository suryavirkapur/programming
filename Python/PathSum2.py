from typing import Optional


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left: TreeNode = left
    self.right: TreeNode = right


class Solution:
  def pathSum(self, root: Optional[TreeNode], targetSum: int) -> list[list[int]]:
    res: list[list[int]] = []

    def dfs(root: Optional[TreeNode], path: list[int], pathSum: int):
      if not root:
        return

      path.append(root.val)
      pathSum += root.val
      # Check if we are on a leaf node,
      # and then push on to currPath and
      if not root.left and not root.right and pathSum == targetSum:
        res.append(path[:])

      dfs(root.left, path, pathSum)
      dfs(root.right, path, pathSum)

      path.pop()

    dfs(root, [], targetSum)
    return res
