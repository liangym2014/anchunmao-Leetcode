# https://leetcode.com/problems/can-make-palindrome-from-substring/
class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        # each element is a 26-bit integer, representing the number of 26 lower-case characters in s[0:i].
        # set bit represents the number of this character is odd
        count = [0] * len(s)
        acc = 0
        for i, c in enumerate(s):
            idx = ord(c) - 97
            bit = acc >> idx
            if bit & 1:  # set the bit to 0
                acc &= ~(1 << idx)
            else:  # set to 1
                acc |= (1 << idx)
                
            count[i] = acc
        
        ans = [False] * len(queries)
        
        for i, [l, r, k] in enumerate(queries):
            # check the oddness/evenness of the number of each characters in s[l: r]
            stat = count[l - 1] ^ count[r] if l else count[r]
            
            odd_count = bin(stat).count('1')
            if (odd_count >> 1) <= k:
                ans[i] = True
        
        return ans
