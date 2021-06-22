# https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        # dictionary, key: element x in nums, val: [neighbor element(s) of x]
        dt = defaultdict(list)
        
        for e1, e2 in adjacentPairs:
            dt[e1].append(e2)
            dt[e2].append(e1)

        mid = adjacentPairs[0][0]
        l = dt[mid][0]
        left = [mid, l]
        right = []
        
        while len(dt[l]) > 1:
            l = dt[l][1] if dt[l][0] == left[-2] else dt[l][0]                
            left.append(l)

                
        if len(dt[mid]) > 1:   # if mid is not at the beginning of nums, it should have another neighbor
            r = dt[mid][1]
            right = [mid, r]
            
            while len(dt[r]) > 1:
                r = dt[r][1] if dt[r][0] == right[-2] else dt[r][0]                    
                right.append(r)
        
            right = right[1:]  # remove the redundant mid at the beginning
            
        return left[::-1] + right  # reverse left list, then concatenate it with right list
