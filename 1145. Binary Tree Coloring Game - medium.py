# https://leetcode.com/problems/binary-tree-coloring-game/
class Solution:
    def btreeGameWinningMove(self, root: Optional[TreeNode], n: int, x: int) -> bool:
        root1 = self.search(root, x)
        l = self.count_nodes(root1.left)
        r = self.count_nodes(root1.right)
        player2 = max(l, r, n - (l + r + 1))
        return player2 > (n - player2)
        
    def search(self, root: Optional[TreeNode], x: int) -> Optional[TreeNode]:
        if not root:
            return None
        
        if root.val == x:
            return root
        
        res = self.search(root.left, x)
        if res != None:
            return res
        
        res = self.search(root.right, x)
        if res != None:
            return res
        
        return None
    
    def count_nodes(self, root: Optional[TreeNode]) -> tuple:
        if not root:
            return 0

        return self.count_nodes(root.left) + self.count_nodes(root.right) + 1
