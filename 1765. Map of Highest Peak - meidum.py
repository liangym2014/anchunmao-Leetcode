# https://leetcode.com/problems/map-of-highest-peak/submissions/
class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m = len(isWater)
        n = len(isWater[0])
        
        ans = [[-1] * n for _ in range(m)]
        
        q = []
        for i in range(m):
            for j in range(n):
                if isWater[i][j]:
                    ans[i][j] = 0   # height for water cell = 0
                    q.append((i,j))
                    
        while q:
            frontier = []
            
            while q:
                r, c = q.pop()
                
                if r >= 1 and ans[r - 1][c] < 0:
                    ans[r - 1][c] = ans[r][c] + 1
                    frontier.append((r - 1, c))
                    
                if r + 1 < m and ans[r + 1][c] < 0:
                    ans[r + 1][c] = ans[r][c] + 1
                    frontier.append((r + 1, c))
                    
                if c >= 1 and ans[r][c - 1] < 0:
                    ans[r][c - 1] = ans[r][c] + 1
                    frontier.append((r, c - 1))
                    
                if c + 1 < n and ans[r][c + 1] < 0:
                    ans[r][c + 1] = ans[r][c] + 1
                    frontier.append((r, c + 1))
                    
            q = frontier
            
        return ans
