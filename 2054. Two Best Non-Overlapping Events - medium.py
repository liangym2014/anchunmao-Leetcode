# https://leetcode.com/problems/two-best-non-overlapping-events/
class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort(key = lambda x: x[0])
        n = len(events)
        
        start_time = [e[0] for e in events]
        max_value = [0] * n
        max_value[-1] = events[-1][2]
        
        ans = 0
        
        for i in range(n - 2, -1, -1):
            val = events[i][2]
            max_value[i] = max(val, max_value[i + 1])
            idx = bisect_right(start_time, events[i][1], i + 1)

            if idx == n:
                ans = max(ans, max_value[i])
            else:
                ans = max(ans, val + max_value[idx])
                
        return ans
