# https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        self.stones = stones
        self.rows = defaultdict(set) # key: row, values: set of indices of stones in the row 
        self.cols = defaultdict(set) # key: column, values: set of indices of stones in the column
        
        for i, stone in enumerate(stones):
            row, col = stone
            self.rows[row].add(i)
            self.cols[col].add(i)

        self.grouped = [False] * len(stones)  # whether stones[i] is included in a group
        num_groups = 0
        
        for i, stone in enumerate(stones):
            if self.grouped[i]:
                continue
                
            row, col = stone
            num_groups += 1
            
            # no other stones in the same row/ column, it forms a group by itself, 
            # otherwise include all its neighbors in the same group
            if len(self.rows[row]) + len(self.cols[col]) > 2:
                self.dfs(i)
        
        return len(stones) - num_groups
    
    def dfs(self, i:int):
        row, col = self.stones[i]
        self.grouped[i] = True
        
        for j in self.rows[row]:
            if not self.grouped[j]:
                self.dfs(j)
            
        for j in self.cols[col]:
            if not self.grouped[j]:
                self.dfs(j)
