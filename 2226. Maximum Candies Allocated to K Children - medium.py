# https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        total = sum(candies)
        if total < k:
            return 0
        
        if total == k:
            return 1
        
        l, r = 1, 10000000
        ans = 0
        while l <= r:
            mid = l + (r - l) // 2
            acc = 0
            for candy in candies:
                acc += candy // mid
                
            if acc < k:
                r = mid - 1
            else:
                ans = mid
                l = mid + 1
                
        return ans
