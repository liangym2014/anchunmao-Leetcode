# https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        if len(arr) == 1:
            return arr[0]
       
        arr = list(accumulate(arr))
        # arr in the following comments is the original input arr
        max_section = arr[0]  # maximum sum of any non-empty section arr[i:k]
        min_val = arr[0]   # minimum sum of section arr[0:i]
        max_val = -arr[0]  # the maximum of (-arr[0:j] + max_section[j - 1])
        ans = arr[0]  # search for max(arr[0:i] - arr[0:j] + max_section[j - 1]), j < i
        
        for i in range(1, len(arr)):
            ans = max(ans, arr[i] + max(max_val, 0))
            max_val = max(max_val, max(max_section, 0) - arr[i])
            max_section = max(arr[i], arr[i] - min_val)
            min_val = min(min_val, arr[i])
            
        return ans
