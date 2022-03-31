# https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/
class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        if len(s) & 1:
            return False
        
        left = []
        change = []
        for i, c in enumerate(s):
            if locked[i] == '0':
                change.append(i)
            elif c == '(':
                left.append(i)
            else:  # c == ')'
                if left:
                    left.pop()
                elif change:
                    change.pop()   # convert an element in change into '('
                else:
                    return False
        
        for idx in left[::-1]:
            if change and change[-1] > idx:
                change.pop()
            else:
                return False
                
        return True
