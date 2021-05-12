# https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/

class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m = len(mat)  # number of rows
        n = len(mat[0])   # number of columns
        
        for i in range(m):
            for j in range(1, n):
                mat[i][j] += mat[i][j - 1]
        
        # print(mat)
        side = 1 # maximum side length
        limit = min(m, n)   # the max value side could achieve
        
        while side <= limit:
            square_found = False
            
            for i in range(m - side + 1):
                for j in range(n - side + 1):
                    acc = 0    # the sum of the square
                    for s in range(side):
                        if j:
                            acc += mat[i + s][j + side - 1] - mat[i + s][j - 1]
                        else:
                            acc += mat[i + s][j + side - 1]
                            
                        if acc > threshold:
                            break
                            
                    # print(side, acc)
                    if acc <= threshold:   # once find a qualified square, break
                        square_found = True
                        break
                        
                if square_found:    # once find a qualified square, break
                    break
                    
            if square_found:
                side += 1
            else:
                return side - 1
            
        return limit
