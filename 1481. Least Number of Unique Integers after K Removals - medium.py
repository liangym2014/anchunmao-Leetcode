# https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        if k == len(arr):
            return 0
        
        counter = Counter(arr)
        
        if k == 0:
            return len(counter)
        
        counter = list(counter.values())
        counter.sort()
        
        acc = 0
        for i in range(len(counter)):
            if acc + counter[i] <= k:
                acc += counter[i]
            else:
                return len(counter) - i
