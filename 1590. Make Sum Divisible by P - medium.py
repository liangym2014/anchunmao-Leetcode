# https://leetcode.com/problems/make-sum-divisible-by-p/
class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        if p == 1:
            return 0
        
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]   # nums becomes the accumulation sum
        
        # suppose we need to remove a subarray at the middle: |....(sum1)| removed subarray |(sum2)....(total)|
        # ==> (total - sum2 + sum1) % p == 0
        # ==> (total + sum1) % p == sum2 % p
        # ==> (the corresponding index i of sum1) < (the corresponding index j of sum2) and find the the minimum (j - i)
        total = nums[-1]
        if (total % p) == 0:
            return 0
        
        m = {(total % p): len(nums) - 1}
        res = len(nums)
        
        for i in range(len(nums) - 2, -1, -1):
            key = (total + nums[i]) % p
            if key in m:
                res = min(m[key] - i, res)
                
            m[nums[i] % p] = i # update the value of this key to the smallest index
        
        # for the case of sum1 == 0, which means the removed subarray on the leftmost of the array
        key = total % p
        if key in m:
            res = min(m[key] + 1, res)
            
        return res if res < len(nums) else -1  # not allowed to remove the whole array
