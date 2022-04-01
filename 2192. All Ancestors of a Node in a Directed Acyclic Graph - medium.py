# https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        self.ans = [set() for _ in range(n)]
        self.nodes = [[] for _ in range(n)]
        
        for edge in edges:
            self.nodes[edge[1]].append(edge[0])
            
        self.visited = [False] * n
        
        for i in range(n):
            if not self.visited[i]:
                self.dfs(i)
            
        return [sorted(list(a)) for a in self.ans]

    def dfs(self, start: int) -> set():
        self.visited[start] = True
        res = set()
        for nxt in self.nodes[start]:
            if self.visited[nxt]:
                res |= (self.ans[nxt] | set([nxt]))
            else:
                res |= self.dfs(nxt)
                
        self.ans[start] = res
        return res | set([start])
