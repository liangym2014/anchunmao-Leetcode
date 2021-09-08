# https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

class Solution:
    def smallestSubsequence(self, s: str) -> str:
        exist = [False] * 26
        last_idx = [0] * 26
        stack = []
        
        for i, c in enumerate(s):
            last_idx[ord(c) - 97] = i
            
        for i, c in enumerate(s):
            if exist[ord(c) - 97]:
                continue
            else:
                while stack and stack[-1] > c and last_idx[ord(stack[-1]) - 97] > i:
                    exist[ord(stack.pop()) - 97] = False
                    
                stack.append(c)
                exist[ord(c) - 97] = True
                
        return "".join(stack)
