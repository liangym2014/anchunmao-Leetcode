# https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        return self.dfs(grid, 0, 0)
    
    def dfs(self, grid, row, col):
        m = len(grid)
        n = len(grid[0])
        
        if row == (m - 1) and col == (n - 1):
            return True
        
        current = grid[row][col]
        grid[row][col] = -grid[row][col]
            
        if current == 1:
            if col + 1 < n and grid[row][col + 1] in [1,3,5] and self.dfs(grid, row, col + 1):
                return True
            if col >= 1 and grid[row][col - 1] in [1,4,6] and self.dfs(grid, row, col - 1):
                return True

        elif current == 2:     
            if row + 1 < m and grid[row + 1][col] in [2,5,6] and self.dfs(grid, row + 1, col):
                return True
            if row >= 1 and grid[row - 1][col] in [2,3,4] and self.dfs(grid, row - 1, col):
                return True

        elif current == 3:
            if col >= 1 and grid[row][col - 1] in [1,4,6] and self.dfs(grid, row, col - 1):
                return True
            if row + 1 < m and grid[row + 1][col] in [2,5,6] and self.dfs(grid, row + 1, col):
                return True
            
        elif current == 4:
            if col + 1 < n and grid[row][col + 1] in [1,3,5] and self.dfs(grid, row, col + 1):
                return True
            if row + 1 < m and grid[row + 1][col] in [2,5,6] and self.dfs(grid, row + 1, col):
                return True
            
        elif current == 5:
            if col >= 1 and grid[row][col - 1] in [1,4,6] and self.dfs(grid, row, col - 1):
                return True
            if row >= 1 and grid[row - 1][col] in [2,3,4] and self.dfs(grid, row - 1, col) :
                return True
            
        else:
            if col + 1 < n and grid[row][col + 1] in [1,3,5] and self.dfs(grid, row, col + 1):
                return True
            if row >= 1 and grid[row - 1][col] in [2,3,4] and self.dfs(grid, row - 1, col):
                return True

        return False
