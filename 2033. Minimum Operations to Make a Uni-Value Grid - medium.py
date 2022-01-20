# https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        num = sorted([e for row in grid for e in row])
        if num[0] == num[-1]:
            return 0

        mn = num[0]
        for e in num:
            if (e - mn) % x:
                return -1
        
        n = len(num)
        if n & 1:
            n = num[n >> 1]
            return sum([abs(e - n) for e in num]) // x

        n1 = num[n >> 1]
        a1 = sum([abs(e - n1) for e in num])
        n2 = num[(n >> 1) - 1]
        a2 = sum([abs(e - n2) for e in num])
        return min(a1, a2) // x
