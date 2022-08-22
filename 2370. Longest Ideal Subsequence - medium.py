# https://leetcode.com/problems/longest-ideal-subsequence/
class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        if k == 25:
            return len(s)
        
        count = [0] * 26
        
        for c in s:
            idx = ord(c) - 97
            lower = max(0, idx - k)
            upper = min(26, idx + k + 1)
            count[idx] = max(count[lower:upper]) + 1
        
        return max(count)
