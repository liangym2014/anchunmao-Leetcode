# https://leetcode.com/problems/rotating-the-box/

class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m = len(box)
        n = len(box[0])
        
        ans = [['.'] * m for _ in range(n)]
        col = 0
        
        for i in range(m - 1, -1, -1):
            vacant = -1  # the first available row in ans[, col]
            for j in range(n - 1, -1, -1):
                if box[i][j] == '*':   # obstacle. Gravity does not affect the obstacles' positions
                    vacant = -1
                    ans[j][col] = '*'
                elif box[i][j] == '.':   # empty
                    if vacant < 0:
                        vacant = j
                elif vacant > 0:          # stone
                    ans[vacant][col] = '#'
                    vacant -= 1
                else:                    # stone
                    ans[j][col] = '#'
            
            col += 1
            
        return ans           
