# https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        ans = 0
        acc = 0
        prev = -1
        
        for i, num in enumerate(nums):
            if num < left:
                continue
                
            interval = i - prev
            
            if acc:
                ans += acc * interval
                
            if num > right:
                acc = 0
            else:
                acc += interval    
            
            prev = i

                
        if acc:
            ans += acc * (len(nums) - prev)
            
        return ans
