# https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/

class Solution:
    def maxNonOverlapping(self, nums: List[int], target: int) -> int:
        dt = defaultdict(int)  # key: sum from nums[0] to nums[i], val: the last index of this sum
        dt[0] = -1
        dt[nums[0]] = 0
        
        count = 0  # non-empty non-overlapping subarrays with sum of target
        end_idx = -1  # the ending index of the last subarray
        
        if nums[0] == target:
            count = 1
            end_idx = 0

        
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]
                
            # if there's a previous sum equal to nums[i] - target,
            # and the index of that sum >= end_idx, count it in
            prev = nums[i] - target
            if prev in dt and dt[prev] >= end_idx:
                count += 1
                end_idx = i

            dt[nums[i]] = i

        return count        
