# https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        # queries[i] = [favoriteTypei, favoriteDayi, dailyCapi]
        ans = [True] * len(queries)
        prev = [0] * len(candiesCount)
        for i in range(len(candiesCount) - 1):
            prev[i + 1] = candiesCount[i] + prev[i]
        
        for i, q in enumerate(queries):
            candy, day, cap = q
            mn = prev[candy]
            mx = prev[candy] + candiesCount[candy]
            # assume on the favorite day i we manage to eat the xth candy of type i, x must meet both requirements:
            # (1) mn < x < mx;   (2) day < x < (day + 1) * cap;
            # therefore, interval (mn, mx) and (day, (day + 1) * cap) must intersect
            if day >= mx or (day + 1) * cap <= mn:
                ans[i] = False
                
        return ans
