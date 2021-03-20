'''
https://leetcode.com/problems/set-mismatch/
'''

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        duplicate = 0
        total = 0
        n = len(nums)
        
        for i in range(n):
            idx = abs(nums[i]) - 1
            
            if nums[idx] < 0:
                duplicate = abs(nums[i])
            else:
                total += abs(nums[i])
                nums[idx] = -nums[idx]

        return [duplicate, (n + 1) * n // 2 - total]
