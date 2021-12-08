# https://leetcode.com/problems/maximum-alternating-subsequence-sum/
class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        pair = [nums[0]]
        ans = 0
        
        for num in nums[1:]:
            if len(pair) == 1:
                if pair[-1] <= num:
                    pair[-1] = num
                else:
                    pair.append(num)
            else:
                if pair[-1] >= num:
                    pair[-1] = num
                else:
                    ans += pair[0] - pair[1]
                    pair = [num]
                    
        return ans + pair[0]
