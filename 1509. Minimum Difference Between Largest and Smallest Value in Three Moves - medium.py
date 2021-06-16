# https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

class Solution:
    def minDifference(self, nums: List[int]) -> int:
        if len(nums) < 5:   # elements are converted into the same number
            return 0
        
        nums.sort()
        
        # case 1: change the last three elements
        res1 = nums[-4] - nums[0]
        
        # case 2: change the first three elements
        res2 = nums[-1] - nums[3]
        
        # case 3: change the first 2 + last 1 elments
        res3 = nums[-2] - nums[2]
        
        # case 4: change the first 1 + last 2 elements
        res4 = nums[-3] - nums[1]
        
        return min(res1, res2, res3, res4)
