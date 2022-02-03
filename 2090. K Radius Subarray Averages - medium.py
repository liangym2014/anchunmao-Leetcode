# https://leetcode.com/problems/k-radius-subarray-averages/
class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        if k == 0:
            return nums
        n = len(nums)
        l = 2 * k + 1
        ans = [-1] * n
        
        if l > n:
            return ans

        nums = list(accumulate(nums))
        ans[k] = nums[l - 1] // l
        for i in range(l, n):
            ans[i - k] = (nums[i] - nums[i - l]) // l
            
        return ans
