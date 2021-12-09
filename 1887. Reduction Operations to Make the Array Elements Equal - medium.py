# https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/
class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        count = Counter(nums)
        
        if len(count) == 1:
            return 0

        count = list(count.items())
        count.sort(key = lambda x: x[0], reverse = True) # sort in descending order of key
        count.pop()
        ops, ans = 0, 0
        
        for _, val in count:
            ops += val
            ans += ops
            
        return ans
