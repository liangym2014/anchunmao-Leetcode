# https://leetcode.com/problems/sell-diminishing-valued-colored-balls/
M = 1000000007
class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        value = 0
        p = sorted([[k, v] for k, v in Counter(inventory).items()], key = lambda x: x[0])

        while len(p) > 1:
            k1, v1 = p[-1]
            k2, v2 = p[-2]

            if v1 * (k1 - k2) <= orders:
                orders -= v1 * (k1 - k2)
                value += v1 * (k1 + k2 + 1) * (k1 - k2) // 2
                value %= M
                p.pop()
                p[-1][1] += v1
            else:
                end = orders // v1
                rem = orders % v1
                orders = 0
                value += v1 * (k1 * 2 - (end - 1)) * end // 2 + (k1 - end) * rem
                value %= M
                break
        
        if orders:
            k, v = p[0]
            end = orders // v
            rem = orders % v
            value += v * (k * 2 - (end - 1)) * end // 2 + (k - end) * rem
            value %= M
        
        return value
