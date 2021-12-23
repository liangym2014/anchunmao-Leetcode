# https://leetcode.com/problems/partition-equal-subset-sum/

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        
        if total & 1:
            return False
        
        total >>= 1
        
        cur = set([0])
        
        for n in nums:
            new_elements = set()
            for e in cur:
                new_elements.add(e + n)
                
            if total in new_elements:
                return True
            
            cur |= new_elements
            
        return False
