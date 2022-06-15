# https://leetcode.com/problems/delete-operation-for-two-strings/
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if word1 == word2:
            return 0
        m, n = len(word1), len(word2)
        a = [0] * n
        
        for i in range(m):
            prev = 0
            for j in range(n):
                tmp = a[j]
                if word1[i] == word2[j]:
                    a[j] = prev + 1
                else:
                    a[j] = max(a[j], a[j - 1] if j else 0)
                prev = tmp
       
        # a[-1] is the length of the longest common subsequence
        return m + n - 2 * a[-1]
