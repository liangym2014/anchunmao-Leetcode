# https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
class Solution:
    def longestBeautifulSubstring(self, word: str) -> int:
        ans = 0
        start = 0
        count = 0
        
        for i in range(1, len(word)):
            if word[i] < word[i - 1]:
                # check whether each vowel appears at least once
                if count == 4:
                    ans = max(ans, i - start)
                    
                start = i
                count = 0
            elif word[i] > word[i - 1]:
                count += 1

        if count == 4:
            ans = max(ans, len(word) - start)
            
        return ans
