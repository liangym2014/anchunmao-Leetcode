# https://leetcode.com/problems/longest-consecutive-sequence/

# solution 2:
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        m = defaultdict(int)
        nums = set(nums)
        
        for num in nums:
            prev = num - 1
            nxt = num + 1
            
            if prev not in nums and nxt not in nums:
                m[num] = 1
            elif prev not in nums:
                val = 1 + m[nxt]
                m[num] = val
                m[m[nxt] + nxt - 1] = val
            elif nxt not in nums:
                val = 1 + m[prev]
                m[num] = val
                m[prev + 1 - m[prev]] = val
            else:
                val = 1 + m[prev] + m[nxt]
                m[num] = val
                m[prev + 1 - m[prev]] = val
                m[m[nxt] + nxt - 1] = val
                
        return max(m.values())
    
# solution 1: not good enough
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
