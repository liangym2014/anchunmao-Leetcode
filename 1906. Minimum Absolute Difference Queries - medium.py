# https://leetcode.com/problems/minimum-absolute-difference-queries/
class Solution:
    def minDifference(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        dt = defaultdict(list)
        for i, num in enumerate(nums):
            dt[num].append(i)
        
        # sort the keys of dt
        dt = dict(sorted(dt.items(), key = lambda x: x[0]))

        ans = [-1] * len(queries)
        
        if len(dt) == 1:
            return ans
        
        for j, (start, end) in enumerate(queries):
            min_difference, last = inf, -1
            
            for k, v in dt.items():
                idx1 = bisect_left(v, start)
                idx2 = bisect_right(v, end)
                
                if idx1 < idx2:
                    if last > 0:
                        min_difference = min(min_difference, k - last)
                        if min_difference == 1:
                            break
                    last = k

            if min_difference != inf:
                ans[j] = min_difference
                
        return ans            
