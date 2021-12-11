# https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        cur = dict()
        
        for n in arr:
            cur[n] = cur.get(n - difference, 0) + 1
   
        return max(cur.values())
