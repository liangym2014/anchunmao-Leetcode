# https://leetcode.com/problems/removing-minimum-and-maximum-from-array/submissions/
class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n = len(nums)
        mx_idx = nums.index(max(nums))
        mn_idx = nums.index(min(nums))  

        if mn_idx < mx_idx:
            return min(mx_idx + 1, n - mn_idx, mn_idx + 1 + n - mx_idx)

        return min(mn_idx + 1, n - mx_idx, mx_idx + 1 + n - mn_idx)
