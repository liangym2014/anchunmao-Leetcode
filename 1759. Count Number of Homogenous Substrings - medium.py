# https://leetcode.com/problems/count-number-of-homogenous-substrings/
modulo = 1000000007

class Solution:
    def countHomogenous(self, s: str) -> int:
        char = s[0]
        count = 1
        ans = 0
        
        for i in range(1, len(s)):
            if s[i] == char:
                count += 1
            else:
                ans += (count * (1 + count)) >> 1
                if ans > modulo:
                    ans %= modulo                
                char = s[i]
                count = 1

        ans += (count * (1 + count)) >> 1
       
        return ans % modulo
