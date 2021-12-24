# https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        self.s =s
        self.k = k
        return self.helper(0, len(s))

    
    def helper(self, start: int, end: int) -> int:
        count = Counter(self.s[start: end])
        skip = [key for key, val in count.items() if val < self.k]
        if not skip:
            return end - start
        
        skip = set(skip)
        sections = []
        
        l = -1
        for i in range(start, end):
            if self.s[i] in skip:
                if l >= 0:
                    sections.append((l, i))
                    l = -1
            elif l < 0:
                l = i

        if l >= 0:
            sections.append((l, end))
            
        max_len = 0
        for left, right in sections:
            max_len = max(max_len, self.helper(left, right))
            
        return max_len
