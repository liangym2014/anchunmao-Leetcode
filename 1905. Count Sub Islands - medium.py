# https://leetcode.com/problems/count-sub-islands/
class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        ans = 0
        self.grid1 = grid1
        self.grid2 = grid2
        
        for i in range(len(grid2)):
            for j in range(len(grid2[0])):
                if grid2[i][j] == 0:
                    continue
                    
                ans += int(self.dfs(i, j))
                
        return ans
    
    def dfs(self, r, c) -> bool:
        self.grid2[r][c] = 0
        cur = (self.grid1[r][c] == 1)
        n, s, w, e = True, True, True, True
        
        if r - 1 >= 0 and self.grid2[r - 1][c] == 1:
            n = self.dfs(r - 1, c)
            
        if r + 1 < len(self.grid2) and self.grid2[r + 1][c] == 1:
            s = self.dfs(r + 1, c)
            
        if c - 1 >= 0 and self.grid2[r][c - 1] == 1:
            w = self.dfs(r, c - 1)
            
        if c + 1 < len(self.grid2[0]) and self.grid2[r][c + 1] == 1:
            e = self.dfs(r, c + 1)
            
        return cur and n and s and w and e
