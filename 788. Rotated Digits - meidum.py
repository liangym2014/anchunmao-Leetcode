# https://leetcode.com/problems/rotated-digits/submissions/
class Solution:
    def rotatedDigits(self, n: int) -> int:
        # if x consists of 0,1,8 only, after rotation still get x
        # if x contains invalid numbers (3,4,7),  get invalid result
        # if x contains 2,5,6,9 and no invalid numbers, that's what we want
        
        count = 0
        for x in range(1, n + 1):
            x = str(x)
            if '3' in x or '4' in x or '7' in x:
                continue
            elif '2' in x or '5' in x or '6' in x or '9' in x:
                count += 1
                
        return count
