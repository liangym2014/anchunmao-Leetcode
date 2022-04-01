# https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        # queries[i] = [favoriteTypei, favoriteDayi, dailyCapi]
        ans = [True] * len(queries)

        for i in range(1,len(candiesCount)):
            candiesCount[i] += candiesCount[i - 1]
        
        for i, q in enumerate(queries):
            candy, day, cap = q
            mn = candiesCount[candy - 1] if candy else 0
            mx = candiesCount[candy]
            # assume on the favorite day i we manage to eat the xth candy of type i, x must meet both requirements:
            # (1) mn < x < mx;   (2) day < x < (day + 1) * cap;
            # therefore, interval (mn, mx) and (day, (day + 1) * cap) must intersect
            if day >= mx or (day + 1) * cap <= mn:
                ans[i] = False
                
        return ans
