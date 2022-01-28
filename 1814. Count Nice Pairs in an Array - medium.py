# https://leetcode.com/problems/count-nice-pairs-in-an-array/
class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        dt = defaultdict(int)  # key = nums[i] - rev(nums[i]), value: count
        for num in nums:
            dt[num - self.rev(num)] += 1

        return sum([((v - 1) * v) >> 1 for v in dt.values()]) % 1000000007

        
    def rev(self, num):
        reversed_str = str(num)[::-1]
        
        if str(num) == reversed_str:
            return num

        for i in range(len(reversed_str)):
            if reversed_str[i] != '0':
                return int(reversed_str[i:])
