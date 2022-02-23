# https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        dt = {}
        dt[0] = 1
        
        for num in nums:
            new_elements = defaultdict(int)
            for k, v in dt.items():
                new_elements[num | k] += v
                
            for k, v in new_elements.items():
                if k in dt:
                    dt[k] += v
                else:
                    dt[k] = v
           
        return dt[max(dt.keys())]
        
