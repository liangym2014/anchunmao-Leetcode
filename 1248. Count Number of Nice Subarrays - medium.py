# https://leetcode.com/problems/count-number-of-nice-subarrays/
from collections import deque
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        ans = 0
        l = -1
        q = deque()
        
        for i, num in enumerate(nums):
            if num & 1:
                if len(q) == k:
                    ans += (i - q[-1]) * (q[0] - l)
                    l = q.popleft()
                    
                q.append(i)
                
        if len(q) == k:
            ans += (len(nums) - q[-1]) * (q[0] - l)
            
        return ans
