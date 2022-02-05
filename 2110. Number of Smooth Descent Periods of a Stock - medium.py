# https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        l = len(prices)
        ans = l
        start = -1
        for i in range(1, l):
            if prices[i - 1] - prices[i] == 1:
                if start < 0:
                    start = i - 1
            elif start >= 0:
                n = i - start
                ans += n * (n - 1) // 2
                start = -1
                
        if start >= 0:
            n = l - start
            ans += n * (n - 1) // 2
            
        return ans
