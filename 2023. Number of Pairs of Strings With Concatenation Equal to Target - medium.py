# https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/
class Solution:
    def numOfPairs(self, nums: List[str], target: str) -> int:
        m = Counter(nums)
        n = len(target)
        ans = 0
        
        for i in range(1,n):
            k1 = target[:i]
            
            if k1 not in m:
                continue
                
            k2 = target[i:]
            
            if k2 not in m:
                continue
            
            if k1 != k2:
                ans += m[k1] * m[k2]
            elif m[k1] > 1:
                ans += m[k1] * (m[k1] - 1)
            
        return ans    
