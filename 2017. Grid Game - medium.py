# https://leetcode.com/problems/grid-game/
class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        l0 = sum(grid[0])  # the remaining points for the 2nd robot to collect at grid[0]
        l1 = 0   # the remaining points for the 2nd robot to collect at grid[1]
        
        min_path = inf   # path with minimum points for the 2nd robot
        
        for i in range(len(grid[0])):
            # the 1st robot's path is grid[0][0:i] + grid[1][i:]
            l0 -= grid[0][i]
            if max(l0, l1) > min_path:
                break
            min_path = max(l0, l1)
            l1 += grid[1][i]
            
        return min_path
