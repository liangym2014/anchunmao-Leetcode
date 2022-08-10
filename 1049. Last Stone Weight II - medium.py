# https://leetcode.com/problems/last-stone-weight-ii/
# this problem is equal to connect the elements in stones list with '+' or '-', so as to minimize the absolute value of the final sum.
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        if len(stones) == 1:
            return stones[0]
        
        acc = set([0])

        for stone in stones:
            tmp = set()
            for e in acc:
                tmp.update([e + stone, e - stone])
                
            acc = tmp
         
        return min([abs(e) for e in acc])
