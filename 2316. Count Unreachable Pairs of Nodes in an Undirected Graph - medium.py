# https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        if n == 1:
            return 0
        
        if not edges:
            return n * (n - 1) // 2
        
        self.nodes = [[] for _ in range(n)]
        self.visited = [False] * n
        ans = 0
        groups = 0
        
        for e in edges:
            l, r = e
            self.nodes[l].append(r)
            self.nodes[r].append(l)
            
        for i in range(n):
            if self.visited[i]:
                continue
            self.visited[i] = True    
            num = self.dfs(i)
            ans += groups * num
            groups += num
                
        return ans
    
    def dfs(self, start: int) -> int:
        res = 1
        
        for n in self.nodes[start]:
            if self.visited[n]:
                continue
                
            self.visited[n] = True
            res += self.dfs(n)
            
        return res
