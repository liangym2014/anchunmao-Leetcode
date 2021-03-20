'''
https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
'''

class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        target = 2**k #total number of binary code of size k
        
        if len(s) < (k + target - 1):
            return False
        
        nums = set() #possible outcome of continuous binary code of size k
        
        #construct a mask with the lowest k bits filled with 1
        mask = (1 << k) - 1
        
        #traverse s
        total = int(s[:k], 2)
        nums.add(total)

        for i in range(k, len(s)):
            total <<= 1
            total |= (ord(s[i]) - 48)
            total &= mask
            nums.add(total)

            if len(nums) == target:
                return True
        
        #print(nums)
        return False
        
