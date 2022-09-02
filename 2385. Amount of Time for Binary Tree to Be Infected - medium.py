# https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        self.start_depth = 0   # the depth of start
        self.mx_distance = 0   # the max distance between start and any node in the tree
        self.compute_distance(root, start, 0)
        return self.mx_distance
    
    def compute_distance(self, root, start, depth) -> int:
        if not root:
            return depth - 1
        
        l = self.compute_distance(root.left, start, depth + 1)
        r = self.compute_distance(root.right, start, depth + 1)
        
        if root.val == start:
            self.mx_distance = max(l, r) - depth   # the max distance between start and a leaf in its subtree
            self.start_depth = depth
            return -1   # start and the ancestors of start should return -1
        
        if l == -1 or r == -1:  # current node is an ancestor of start
            self.mx_distance = max(self.mx_distance, max(l, r) + self.start_depth - 2 * depth)
            return -1
        
        return max(l, r)
