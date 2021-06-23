# https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        self.res = 0
        self.split(s, 0, set())
        return self.res
    
    def split(self, s, start, prev):
        if start == len(s):
            self.res = max(self.res, len(prev))
            return

        for i in range(start + 1, len(s) + 1):
            if s[start:i] not in prev:
                self.split(s, i, prev | {s[start:i]})
