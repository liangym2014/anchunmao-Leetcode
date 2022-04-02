# https://leetcode.com/problems/count-good-numbers/
M = 1000000007
class Solution:
    def countGoodNumbers(self, n: int) -> int:
        even = (n + 1) // 2 if (n & 1) else (n // 2)
        odd = (even - 1) if (n & 1) else even
        even_digits = self.dc(5, even)
        odd_digits = self.dc(4, odd)
        return (even_digits * odd_digits) % M
    
    def dc(self, element, total):
        if total == 0:
            return 1
        
        if total == 1:
            return element
        
        mid = total // 2
        res = self.dc(element, mid) ** 2
        
        if total & 1:
            res *= element
            
        return res % M
