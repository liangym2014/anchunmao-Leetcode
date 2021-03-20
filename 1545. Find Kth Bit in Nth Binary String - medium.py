'''
https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
'''

class Solution:
    s1 = '0'
    
    def findKthBit(self, n: int, k: int) -> str:
        while len(Solution.s1) < k:
            Solution.s1 += '1' + self.postfix(Solution.s1)
            
        return Solution.s1[k - 1]
            
            
    def postfix(self, s: str) -> str:
        res = ''
        
        for i in reversed(s):
            res += '0' if i == '1' else '1'
            
        return res
