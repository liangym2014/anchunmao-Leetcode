# https://leetcode.com/problems/destroy-sequential-targets/
class Solution:
    def destroyTargets(self, nums: List[int], space: int) -> int:
        if space == 1:
            return min(nums)
        
        m = {}
        mx_series = 1
        for num in nums:
            key = num % space
            if key in m:
                m[key][0] += 1
                mx_series = max(mx_series, m[key][0])
                m[key][1] = min(m[key][1], num)
            else:
                m[key] = [1, num]
        
        return min([val for counter, val in m.values() if counter == mx_series])
