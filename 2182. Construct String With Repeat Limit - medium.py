# https://leetcode.com/problems/construct-string-with-repeat-limit/
class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        v = sorted([[k, v] for k, v in Counter(s).items()], key = lambda x: x[0])
        res = ""
        while len(v) > 1:
            if not res or v[-1][0] != res[-1]:
                d = min(v[-1][1], repeatLimit)

                res += v[-1][0] * d
                v[-1][1] -= d

                if v[-1][1] == 0:
                    v.pop()
            else:
                res += v[-2][0]
                v[-2][1] -= 1

                if v[-2][1] == 0:
                    v.pop(-2)
            
        if v:
            if not res or res[-1] != v[0][0]:
                res += v[0][0] * min(repeatLimit, v[0][1])
                
        return res
