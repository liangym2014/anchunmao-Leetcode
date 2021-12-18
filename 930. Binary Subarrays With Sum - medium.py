# https://leetcode.com/problems/binary-subarrays-with-sum/
class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        total = 0
        dt = defaultdict(int)
        dt[0] = 1
        ans = 0
        
        for num in nums:
            total += num
            prev = total - goal
            if prev in dt:
                ans += dt[prev]
                
            dt[total] += 1
            
        return ans
