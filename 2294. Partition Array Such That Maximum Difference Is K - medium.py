# https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/
class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums = set(nums)
        if k == 0:
            return len(nums)
        
        arr = [0] * (max(nums) + 1)
        for num in nums:
            arr[num] = 1
            
        i = min(nums)
        ans = 0
        while i < len(arr):
            while i < len(arr) and arr[i] == 0:
                i += 1
                
            if i < len(arr):
                ans += 1
                
            i += k + 1
        return ans    
