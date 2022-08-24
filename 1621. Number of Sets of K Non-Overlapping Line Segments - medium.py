# https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        M = 1000000007
        # suppose we have a 2-D matrix, size: n * (k + 1), 
        # each row represents the ways of drawing 0, 1, ... k non_overlapping line segements over n points
        
        # for ith points, there exist at most i non-overlapping line segments.
        # col_sum[k] represents the column sum of (mat[k][k] + mat[k + 1][k] + ... + mat[i - 1][k])
        col_sum = [0] * (k + 1)
        col_sum[0] = 1
        
        # the ways of drawing 0, 1, ... k line segements for mat[i - 1,:]
        prev_row = [0] * (k + 1)
        
        # consider drawing j line segments over points [0, 1, ... ,i]
        for i in range(1, n):
            colsum_on_left = col_sum[0]  # the col_sum including row 0 ~ row (i - 1) for (j - 1) line segments
            col_sum[0] += 1
            
            lim = min(i, k) + 1
            for j in range(1, lim):
                # there're two ways of drawing j line segments:
                # 1. let j line segments ending before i. => prev_row[j]
                # 2. let (j - 1) segments ending at (j - 1), j, ..., (i - 1), and the last line segment starting 
                # at (j - 1), j, ..., (i - 1). => sum(mat[j - 1, j - 1] + ... + mat[i - 1, j - 1])
                acc = prev_row[j] + colsum_on_left
                # modulo
                acc %= M
                
                # update pre_row
                prev_row[j] = acc
                # update colsum_on_left, add mat[i][j] to col_sum[j]
                colsum_on_left = col_sum[j]
                col_sum[j] += acc

        return prev_row[-1]
