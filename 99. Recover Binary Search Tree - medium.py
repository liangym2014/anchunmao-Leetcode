# https://leetcode.com/problems/recover-binary-search-tree/
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.cliff = []
        self.in_order(None, root)
        
        if len(self.cliff) == 1:
            l, r = self.cliff[0]
        else:
            l, _ = self.cliff[0]
            _, r = self.cliff[1]
            
        l.val, r.val = r.val, l.val
        
        
    def in_order(self, prev: Optional[TreeNode], root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return prev
        
        prev = self.in_order(prev, root.left)
        
        if prev and prev.val > root.val:
            self.cliff.append((prev, root))
        
        prev = self.in_order(root, root.right)
        
        return prev
