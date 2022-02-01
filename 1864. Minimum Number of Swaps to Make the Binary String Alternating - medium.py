# https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
class Solution:
    def minSwaps(self, s: str) -> int:
        n = len(s)
        if n == 1:
            return 0
        
        count = Counter(s)
        if len(count) == 1 or abs(count['0'] - count['1']) > 1:
            return -1
        
        s = [int(i) for i in s]
        if count['0'] >= count['1']:
            # "0101...10(1)"
            ans, num = 0, 0
            for c in s:
                if c != num:
                    ans += 1
                num = not num
                        
        if count['1'] >= count['0']:
            # "1010...101(0)"
            res, num = 0, 1
            for c in s:
                if c != num:
                    res += 1
                num = not num
        
        return min(ans, res) >> 1 if count['0'] == count['1'] else (ans >> 1) if count['0'] > count['1'] else (res >> 1)       
