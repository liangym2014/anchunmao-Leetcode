# https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
class Solution:
    def minimumDeletions(self, s: str) -> int:
        # end_a: the number of deletions to make s[0:i] ending with 'a' balanced
        # end_b: the number of deletions to make s[0:i] ending with 'b' balanced
        end_a, end_b = 0, 0
        
        for c in s:
            if c == 'a':
            # to make s[0:i + 1] end with 'a' <==> s[0:i + 1] = (prev ending with 'a') + 'a'.
            # end_a doesn't need to change.
            
            # to make s[0:i + 1] end with 'b' <==>  s[0:i + 1] = (prev ending with 'b') + 'a'.
            # need to delete the current 'a' plus all the deletions end_b required ==> end_b = end_b + 1                
                end_b += 1
            else:
            # to make s[0:i + 1] end with 'b' <==> s[0:i + 1] = prev + 'b'
            # choose the minimum deletions prev requires to become balanced ==> end_b = min(end_a, end_b)
            
            # to make s[0:i + 1] end with 'a' <==> s[0:i + 1] = (prev ending with 'a') + 'b'.
            # need to delete the current 'b' plus all the deletions end_a required ==> end_a = end_a + 1.            
                end_b = min(end_a, end_b)
                end_a += 1                
        
        return min(end_a, end_b)
