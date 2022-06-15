# https://leetcode.com/problems/maximum-total-importance-of-roads/
class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        m = Counter([e for road in roads for e in road])
        return sum([num * count for num, count in zip(range(n, 0, -1), sorted(m.values(), key = lambda x: -x))])
