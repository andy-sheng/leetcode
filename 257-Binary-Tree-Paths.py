# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    result = []
    def findPath(self, root, path):
        if path == "":
            path = str(root.val)
        else:
            path += "->" + str(root.val)

        if root.left == None and root.right == None:
            self.result.append(path)
            return

        if root.left != None:
            self.findPath(root.left, path)
        if root.right != None:
            self.findPath(root.right, path)

    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        self.result = []
        if root == None:
            return []
        self.findPath(root, "")
        return self.result
