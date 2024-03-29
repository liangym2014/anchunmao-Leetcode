'''
https://leetcode.com/problems/wiggle-subsequence/
'''

class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        step = 0
        
        if len(nums) < 2:
            return len(nums)
        
        i = 1
        while i < len(nums) and nums[i] == nums[i - 1]:
            i += 1
            
        if i == len(nums):
            return step + 1
        
        step += 1
        sign = 1 if nums[i] > nums[i - 1] else -1
        
        while i < len(nums):
            if nums[i] > nums[i - 1]:
                if sign < 0:
                    sign = 1
                    step += 1
            elif nums[i] < nums[i - 1]:
                if sign > 0:
                    sign = -1
                    step += 1
            
            i += 1
            
        return step + 1
