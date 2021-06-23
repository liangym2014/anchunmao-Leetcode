# https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        row_size = len(rowSum)
        col_size = len(colSum)
        
        mat = [[0] * col_size for _ in range(row_size)]
        
        for i in range(row_size):
            for j in range(col_size):
                if rowSum[i] == 0:
                    break
                    
                if colSum[j] == 0:
                    continue
                    
                mat[i][j] = min(rowSum[i], colSum[j])
                rowSum[i] -= mat[i][j]
                colSum[j] -= mat[i][j]
                
        return mat
