# https://leetcode.com/problems/longest-consecutive-sequence/
class Union_find:
    def __init__(self):
        self.group = []
        self.m = dict()

        
    def find(self, idx):
        gid = self.group[idx]
        if gid != idx:
            gid = self.find(gid)
            
        return gid

    
    def union(self, x):
        pre, pre_lead = x - 1, -1
        pos, pos_lead = x + 1, -1

        if pre in self.m:
            pre_lead = self.find(self.m[pre])
            
        if pos in self.m:
            pos_lead = self.find(self.m[pos])

        if pre_lead >= 0:
            self.m[x] = pre_lead
            
            if pos_lead >= 0:
                self.group[pos_lead] = pre_lead
        else:
            if pos_lead < 0:
                new_group = len(self.group)
                self.m[x] = new_group
                self.group.append(new_group)
            else:
                self.m[x] = pos_lead

                
    def longest_sequence(self):
        count = []
        
        for g in self.m.values():
            count.append(self.find(g))
            
        return Counter(count).most_common(1)[0][1]
    
    
    
    
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        uf = Union_find()
        
        for num in set(nums):
            uf.union(num)
            
        return uf.longest_sequence()
