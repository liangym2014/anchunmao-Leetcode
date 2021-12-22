# https://leetcode.com/problems/add-minimum-number-of-rungs/
class Solution:
    def addRungs(self, rungs: List[int], dist: int) -> int:
        mul = rungs[0] / dist
        ans = ceil(mul) - 1 if mul >= 1 else 0
        i = 0
        
        while (i + 1) < len(rungs):
            mul = (rungs[i + 1] - rungs[i])/ dist
            if mul >= 1:
                ans += ceil(mul) - 1
                i += 1
                continue

            idx = bisect_right(rungs, rungs[i] + dist, i)
            i = idx - 1

        return ans
