# https://leetcode.com/problems/number-of-longest-increasing-subsequence/
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        sq = [nums[0]]
        
        dt = defaultdict(list)
        dt[0] = [0]
        
        count = [1] * n
        
        for i in range(1, n):
            idx = bisect_left(sq, nums[i])
            if idx == len(sq):
                sq.append(nums[i])
            else:
                sq[idx] = nums[i]
            
            dt[idx].append(i)
            
            if idx:
                count[i] = sum([count[val] for val in dt[idx-1] if nums[val] < nums[i]])


        return sum([count[i] for i in dt[len(sq) - 1]])
