# https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        letters = [0] * 256
        l = 0
        ans = 1
        for i in range(len(s)):
            if letters[ord(s[i])]:
                ans = max(ans, i - l)
                
                while letters[ord(s[i])]:
                    letters[ord(s[l])] = 0
                    l += 1
                    
            letters[ord(s[i])] = 1                    
        return max(ans, len(s) - l)
