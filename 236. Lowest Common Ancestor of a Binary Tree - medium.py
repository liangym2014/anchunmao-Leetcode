# https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.visited = set()
        self.p = p
        self.q = q
        self.count = 0
        return self.dfs(root)
        
        
    def dfs(self, root: 'TreeNode') -> 'TreeNode':
        if not root:
            return None
        
        # if current is one of the targets, current node must be in the path from targets -> root node
        if root == self.p or root == self.q:
            self.visited.add(root)
            self.count += 1
            
        l  = self.dfs(root.left)
        # if a target or (path from target -> root node) exist in left branch, 
        # current node must be in the (path from targets -> root node) too
        if l:
            if self.count == 2:  # if both targets are found
                # if current node is already visited, this is the lowest common ancestor.
                # otherwise, l must be a lower ancestor than current node
                return root if root in self.visited else l
            else:
                # otherwise, only one of the targets is found, add current node to the path.
                # continue searching for the other one
                self.visited.add(root) 
        

        r = self.dfs(root.right)
        if r:
            if self.count == 2:
                return root if root in self.visited else r
            else:
                self.visited.add(root)


        if root in self.visited:
            return root
        
        return None
