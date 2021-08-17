# https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/

class Solution:
    def minElements(self, nums: List[int], limit: int, goal: int) -> int:
        diff = goal - sum(nums)
        n = abs(diff) / limit
        return int(n) + (n != int(n))
