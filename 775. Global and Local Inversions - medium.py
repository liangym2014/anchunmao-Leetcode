'''
https://leetcode.com/problems/global-and-local-inversions/
'''
class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        for i, x in enumerate(A):
            # case 1(x == i): no. of global inversion and no. of local inversion are both equal to 0
            
            # case 2: divide [0,1,.., N-1] into multiple consecutive pairs, swap the two elements in each pair;
            # no. of global inversion and no. of local inversion are both equal to N/2
            
            if abs(x - i) > 1:
                return False
            
        return True
