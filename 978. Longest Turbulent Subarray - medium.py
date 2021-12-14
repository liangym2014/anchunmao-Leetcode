# https://leetcode.com/problems/longest-turbulent-subarray/
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        n = len(arr)
        if n == 1:
            return 1
        
        ans, count, i = 1, 1, 0

        while (i + 1) < n:
            sign = 1
            
            if arr[i] == arr[i + 1]:
                i += 1
                continue
                
            count = 2
            if arr[i] < arr[i + 1]:
                sign = -1
                
            i += 1
            while (i + 1) < n:
                t = (arr[i] - arr[i + 1]) * sign
                
                if t >= 0:
                    ans = max(ans, count)
                    break
                else:
                    sign = -sign
                    count += 1
                    i += 1
            
        return max(ans, count)
