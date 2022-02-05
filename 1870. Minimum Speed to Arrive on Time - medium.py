# https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        l, r = 1, 10000000

        if len(dist) - 1 + (dist[-1] / r) > hour:
            return -1

        while l <= r:
            mid = l + ((r - l) >> 1)
            total = self.compute_sum(dist, mid)

            if total > hour:  # mid is too small
                l = mid + 1
            else:   # mid is too large or proper
                r = mid - 1
   
        return l + (self.compute_sum(dist, l) > hour)

    def compute_sum(self, dist: List[int], divisor: int) -> float:
        return sum([ceil(x / divisor) for x in dist[:-1]]) + dist[-1] / divisor
