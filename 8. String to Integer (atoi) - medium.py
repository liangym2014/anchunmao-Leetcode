# https://leetcode.com/problems/string-to-integer-atoi/
class Solution:
    def myAtoi(self, s: str) -> int:
        start = -1
        for i in range(len(s)):  # wipe out whitespaces
            if s[i] != ' ':
                start = i
                break
                
        if start < 0: # all whitespaces
            return 0
        
        positive = True  # check the sign
        if s[start] == '-':
            start += 1
            positive = False
        elif s[start] == '+':
            start += 1

        while start < len(s) and s[start] == '0':  # ignore leading zeros
            start += 1

        if start == len(s):
            return 0

        lim = min(len(s), start + 10)
        i = start
        while i < lim:
            if s[i] >= '0' and s[i] <= '9':
                i +=1
                continue

            break
        
        if i == start:  # no valid digits
            return 0
        
        if i == lim and i < len(s) and s[i] >= '0' and s[i] <= '9':  # exceed lower bound or upper bound
            return 2147483647 if positive else -2147483648

        num = int(s[start: i])
        return min(num, 2147483647) if positive else min(num, 2147483648) * (-1)
