# https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        m, n = len(maze), len(maze[0])
        steps = 1
        cur = [entrance]
        maze[entrance[0]][entrance[1]] = '+'
        
        while cur:
            nxt = []
            
            for r, c in cur:
                for x in [r - 1, r + 1]:
                    if x < 0 or x >= m:
                        continue

                    if maze[x][c] == '.':
                        if x == 0 or x == (m - 1) or c == 0 or c == (n - 1):
                            return steps
                        nxt.append((x, c))
                        maze[x][c] = '+'
 
                for y in [c - 1, c + 1]:
                    if y < 0 or y >= n:
                        continue

                    if maze[r][y] == '.':
                        if r == 0 or r == (m - 1) or y == 0 or y == (n - 1):
                            return steps
                        nxt.append((r, y))
                        maze[r][y] = '+' 
                        
            cur = nxt
            steps += 1

        return -1
