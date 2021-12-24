# https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/
class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        n = len(nums)
        # \/\
        last = nums[0]
        ops1 = 0        
        for i in range(1, n):
            if i & 1:
                if nums[i] >= last:
                    ops1 += nums[i] - (last - 1)  # nums[i] ==> nums[i-1] - 1
                    last -= 1
                else:
                    last = nums[i]
            else:
                if nums[i] <= last:
                    ops1 += last - (nums[i] - 1)  # nums[i-1] ==> nums[i] - 1
                    
                last = nums[i]

        # /\/\
        last = nums[0]        
        ops2 = 0
        for i in range(1, n):
            if i & 1:
                if nums[i] <= last:
                    ops2 += last - (nums[i] - 1)  # nums[i-1] ==> nums[i] - 1
                    
                last = nums[i]
            else:
                if nums[i] >= last:
                    ops2 += nums[i] - (last - 1)  # nums[i] ==> nums[i-1] - 1
                    last -= 1
                else:
                    last = nums[i]
                    
        return min(ops1, ops2)
