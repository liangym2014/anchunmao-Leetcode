# https://leetcode.com/problems/sum-of-beauty-in-the-array/
class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        n = len(nums)
        mx, mn = 0, nums[-1]
        max_arr = [0] * n
        beauty = [0] * n
        
        for i in range(n):
            mx = max(mx, nums[i])
            max_arr[i] = mx
            
        for i in range(n - 2, 0, -1):
            if max_arr[i-1] < nums[i] and nums[i] < mn:
                beauty[i] = 2
            elif nums[i-1] < nums[i] and nums[i] < nums[i+1]:
                beauty[i] = 1
            mn = min(mn, nums[i])
            
        return sum(beauty)
