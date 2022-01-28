# https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        dt = Counter(words)
        diff, even = 0, 0
        odd = []

        for k, v in dt.items():
            if k[0] == k[-1]:
                if v & 1:
                    odd.append(v)
                else:
                    even += v
                continue
                
            reverse = k[-1] + k[0]
            if reverse in dt:
                diff += min(v, dt[reverse])

        l = 2 * (diff + even)
        if odd:
            odd.sort()
            l += 2 * (odd[-1] + sum(odd[:-1]) - (len(odd) - 1))
            
        return l
