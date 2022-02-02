# https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        self.m = defaultdict(list)
        for a, b in edges:
            self.m[a].append(b)
            self.m[b].append(a)

        self.ans = [0] * n
        self.visited = [False] * n
        self.labels = labels
        self.dfs(0)
        return self.ans
    
    def dfs(self, root) -> dict():
        self.visited[root] = True
        c = self.labels[root]        
        
        acc = defaultdict(int)
        acc[c] = 1
        
        for child in self.m[root]:
            if self.visited[child] == False:
                for k, v in self.dfs(child).items():
                    acc[k] += v

        self.ans[root] = acc[c]
        return acc
