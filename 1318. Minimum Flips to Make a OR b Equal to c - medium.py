# https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        ans = 0
        
        for i in range(32):
            bit_a = a & (1 << i)
            bit_b = b & (1 << i)
            bit_c = c & (1 << i) 
            
            if bit_c:
                if bit_a or bit_b:
                    continue
                else:
                    ans += 1
            else:
                if bit_a:
                    ans += 1
                if bit_b:
                    ans += 1
                    
        return ans
