# https://leetcode.com/problems/path-with-maximum-probability/

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        nodes = [[] for _ in range(n)]   # list of (edge, succProb) for each node
        
        for i in range(len(edges)):
            nodes[edges[i][0]].append((edges[i][1], succProb[i]))
            nodes[edges[i][1]].append((edges[i][0], succProb[i]))
        
        if len(nodes[start]) == 0 or len(nodes[end]) == 0:   # no path from start to end
            return 0
        
        prob = [0] * n  # maxium successful probability for the path from start to node i
        prob[start] = 1
        
        current = [start]
        
        while current:
            frontier = set()  # nodes to explore in the next iteration
            
            for node in current:
                if node == end:
                    continue

                for other, p in nodes[node]:
                    if prob[node] < prob[other]:
                        continue
                    if p * prob[node] > prob[other]:
                        prob[other] = p * prob[node]
                        frontier.add(other)
        
            current = list(frontier)  # no duplicates in current
            
        return prob[end]
