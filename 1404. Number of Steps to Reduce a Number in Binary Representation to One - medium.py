# https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

class Solution:
    def numSteps(self, s: str) -> int:
        num = int(s, 2)
        # print(num)
        # print(len(s))
        steps = 0
        
        while num > 1:
            if num & 1:
                num += 1
            else:
                num >>= 1
            steps += 1
            
        return steps
