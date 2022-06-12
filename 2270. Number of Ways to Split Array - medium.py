# https://leetcode.com/problems/number-of-ways-to-split-array/
from itertools import accumulate
class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        total = sum(nums)
        return len(list(filter(lambda x: 2 * x >= total, list(accumulate(nums))[:-1])))
