# https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        h = []
        n = len(matrix) * len(matrix[0])

        if k > (n // 2):
            f = self.max_heap  # only insert elements < h[0]
            k = n - k + 1
        else:
            f = self.min_heap # only insert elements > h[0]
            
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if not i and not j:
                    row = matrix[i][j]
                elif not i:
                    matrix[i][j] ^= row
                    row = matrix[i][j]
                elif not j:
                    row = matrix[i][j]                    
                    matrix[i][j] ^= matrix[i-1][j]
                else:
                    row ^= matrix[i][j]
                    matrix[i][j] = (matrix[i - 1][j] ^ row)

                f(h, k, matrix[i][j])
                
        return h[0] if f == self.min_heap else -h[0]
 
    def min_heap(self, heap, k, element):
        if len(heap) < k:
            heappush(heap, element)
        elif element > heap[0]:
            heappushpop(heap, element)

            
    def max_heap(self, heap, k, element):
        if len(heap) < k:
            heappush(heap, -element)
        elif (-element) > heap[0]:
            heappushpop(heap, -element)
