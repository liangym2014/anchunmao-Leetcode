# https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/
  
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        # check the number of x and y, both should be even
        n = len(s1)
        s1_x = len([x for x in s1 if x == 'x'])
        s2_x = len([x for x in s2 if x == 'x'])

        num_x = s1_x + s2_x
        
        # only one type of letter in both strings
        if num_x == 0 or num_x == (2 * n):
            return 0
        
        # if either of them is odd
        if num_x & 1:
            return -1
        
        # go through both strings
        """
        case 1: swap twice
        x   y        y   y     x   y
        y   x    =>  x   x  => x   y

        case 2: swap once
        x   x        y   x
        y   y    =>  y   x
        """
        xy, yx = 0, 0  # the number of pair (x, y) and (y, x)
        for e1, e2 in zip(s1, s2):
            if e1 == e2:
                continue
                
            if e1 == 'x':
                xy += 1
            else:
                yx += 1
                
        ans = (xy >> 1) + (yx >> 1)

        if xy % 2:
            ans += 2
            
        return ans
