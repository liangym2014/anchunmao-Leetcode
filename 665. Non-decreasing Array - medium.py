# https://leetcode.com/problems/non-decreasing-array/
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 3:
            return True
        
        decrease = False
        for i in range(n - 1):
            if nums[i] <= nums[i + 1]:
                continue
            
            if decrease:  # have a previous decrease 
                return False
            
            decrease = True
            if i == 0:   # modify nums[0] to a smaller value
                continue

            if nums[i - 1] <= nums[i + 1]:  # modify nums[i] to nums[i - 1] or nums[i + 1]
                continue
                
            if i + 2 < n:                    
                if nums[i] <= nums[i + 2]:  # modify nums[i + 1] to nums[i] or nums[i + 2]
                    nums[i + 1] = nums[i]
                else:
                    return False   # need to modify two or more elements
                
        return True
