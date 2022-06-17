# https://leetcode.com/problems/longest-palindromic-substring/
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if s == s[::-1]:
            return s
        
        start = 0   # the start index of the longest palindromic substring
        mx_len = 1  # the length of the longest palindromic substring
        prev2 = list(range(len(s)))

        prev1 = []
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                prev1.append(i - 1)
                
        if prev1:
            start = prev1[0]
            mx_len = 2
            
        l = 3  # the length of the substring currently evaluated
        while prev2 or prev1:
            mid = l - 2  # the substring of length l: X + s[prev2[idx]: prev2[idx] + mid] + X

            tmp = []
            if prev2:
                if prev2[0] < 1:
                    prev2.pop(0)
                    
                for idx in prev2:
                    if idx + mid >= len(s):
                        break
                    if s[idx - 1] == s[idx + mid]:
                        tmp.append(idx - 1)

                if tmp:
                    start = tmp[0]
                    mx_len = l

            prev2, prev1 = prev1, tmp
            l += 1
        
        return s[start: start + mx_len]
