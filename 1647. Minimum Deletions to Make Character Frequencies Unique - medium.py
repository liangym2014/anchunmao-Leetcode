# https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
class Solution:
    def minDeletions(self, s: str) -> int:
        freq = list(Counter(list(s)).values())
        freq.sort(reverse = True)  # sort in descending order
        freq.append(0)
        
        duplicates = []
        j = 0
        ans = 0
        
        for i in range(1, len(freq)):
            if freq[i - 1] == freq[i]:
                duplicates.append(freq[i])
            elif (freq[i - 1] - 1) > freq[i]:
                num = freq[i - 1] - 1
                while num > freq[i] and j < len(duplicates):
                    ans += duplicates[j] - num
                    num -= 1
                    j += 1
            
        return ans + sum(duplicates[j:])
