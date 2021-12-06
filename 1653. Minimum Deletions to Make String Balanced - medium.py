# https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
class Solution:
    def minimumDeletions(self, s: str) -> int:
        count_a, count_b = 0, 0  # number of 'a' or 'b' in s[0:i]
        
        # remove_a: the number of deletions of 'a' to make s[0:i] balanced
        # remove_b: the number of deletions of 'b' to make s[0:i] balanced
        remove_a, remove_b = 0, 0
        
        for c in s:
            if c == 'a':
                count_a += 1
                
                # if end with 'b': besides all the 'a' that need to be remove in previous section, also remove current 'a'
                remove_a += 1               
                # if end with 'a', must remove any 'b' on the left
                remove_b = count_b
            else:
                count_b += 1
                
                # suppose the section on the left of c is already balanced, then letting s[0:i] + c end with 'b', 
                # will always require less deletions than it ending with 'a', since the last character of 'b' doesn't
                # need to be removed.
                # for the section of s[0:i], would require at least min(remove_a, remove_b) deletions to become balanced
                remove_a = min(remove_a, remove_b)

        
        return min(remove_a, remove_b)
