# https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        psum = 0 # the positive sum of a subarray
        nsum = 0 # the negative sum of a subarray
        
        positive_sum = -inf # the maximum positive sum of any subarrays
        negative_sum = inf # the minimum negative sum of any subarrays
        
        for n in nums:
            psum += n
            nsum += n
            
            if psum < 0:
                psum = 0
            else:
                positive_sum = max(positive_sum, psum)
                
            if nsum > 0:
                nsum = 0
            else:
                negative_sum = min(negative_sum, nsum)
                
        if positive_sum == -inf:
            return -negative_sum
        
        if negative_sum == inf:
            return positive_sum
        
        return max(positive_sum, -negative_sum)
