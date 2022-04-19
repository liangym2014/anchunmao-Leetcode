# https://leetcode.com/problems/fraction-addition-and-subtraction/
from math import lcm, gcd
class Solution:
    def fractionAddition(self, expression: str) -> str:
        numerators = []
        denominators = []

        for str_num in re.split('[+-]', expression):
            if str_num:
                num  = [int(x) for x in str_num.split('/')]
                numerators.append(num[0])
                denominators.append(num[1])

        common_multiple = lcm(*denominators)
       
        if expression[0] != '-':
            s = '+' + expression
        else:
            s = expression
   
        acc = 0 
        i = 0
        for c in s:
            if c == '+':
                acc += (common_multiple// denominators[i]) * numerators[i]
                i += 1
            elif c == '-':
                acc -= (common_multiple// denominators[i]) * numerators[i]
                i += 1
        
        factor = gcd(acc, common_multiple)

        return str(acc // factor) + '/' + str(common_multiple // factor)
