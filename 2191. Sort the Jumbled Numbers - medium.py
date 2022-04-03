# https://leetcode.com/problems/sort-the-jumbled-numbers/
class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        in_order = True
        for i, val in enumerate(mapping):
            if i != val:
                in_order = False
                break
                
        if in_order:
            nums.sort()
            return nums

        for k, num in enumerate(nums):
            n = [mapping[ord(c) - 48] for c in str(num)]  # list of integer
            # remove leading zeros
            i = 0
            while i < len(n):
                if n[i]:
                    mapped_val = int("".join([chr(48+j) for j in n[i:]]))
                    break
                    
                i += 1
                
            if i == len(n): # all zeros
                mapped_val = 0
                
            nums[k] = (mapped_val, num)
            
        nums.sort(key = lambda x: x[0])
        return [val for _, val in nums]
