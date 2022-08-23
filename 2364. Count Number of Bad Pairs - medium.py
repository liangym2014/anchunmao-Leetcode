# https://leetcode.com/problems/count-number-of-bad-pairs/
class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        counter = Counter([(num - i) for i, num in enumerate(nums)])

        acc = 0
        ans = 0
        for i in counter.values():
            ans += i * acc
            acc += i
            
        return ans
