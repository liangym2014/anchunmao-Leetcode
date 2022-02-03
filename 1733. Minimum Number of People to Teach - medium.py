# https://leetcode.com/problems/minimum-number-of-people-to-teach/
class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        languages = [set(l) for l in languages]

        groups = set() # indices of users that can't communicate with at least one of their friends
        for u, v in friendships:
            if (languages[u - 1] & languages[v - 1]) == set():
                groups.update([u,v])
        
        if len(groups) == 0:
            return 0
        
        count = Counter([l for x in groups for l in languages[x - 1]])
        count = sorted(count.values())
        return len(groups) - count[-1]
