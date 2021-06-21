# https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/

class Solution:
    def minInsertions(self, s: str) -> int:
        stack = []
        ans = 0  # number of insertions 
        
        for c in s:    # '(' => 1, ')' => -0.5
            if c == '(':
                while stack:
                    if stack[-1] == 1:        # previous: (
                        break
                    elif stack[-1] == -0.5:   # previous: )   
                        ans += 2
                    else:                     # previous: )) or ()
                        ans += 1
                        
                    stack.pop() 
                
                stack.append(1)
            else:       # c == ')'
                if not stack:
                    stack.append(-0.5)
                elif stack[-1] == -1:      # previous: ))
                    stack.pop()
                    ans += 1
                    stack.append(-0.5)
                elif stack[-1] == 0.5:   # previous: ()
                    stack.pop()
                else:                    # previous: ( or )         
                    stack[-1] -= 0.5
          
        for num in stack:
            if num in [-1, 0.5]:
                ans += 1
            else:
                ans += 2
                
        return ans
