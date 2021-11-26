# https://leetcode.com/problems/maximize-the-confusion-of-an-exam/submissions/

class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        count = Counter(list(answerKey))
        n = len(answerKey)
        # print(n, count)
        if len(count) == 1:  # all 'T' or all 'F'
            return n
        
        if count['T'] <= k or count['F'] <= k:
            return n
       
        # convert 'F' to 'T' to obtain the longest consecutive 'T' string
        l = 0
        remain = k
        mx1 = 0
        
        for r in range(n):
            if answerKey[r] == 'F':
                if remain:
                    remain -= 1
                else:
                    while answerKey[l] != 'F':
                        l += 1
                    l += 1
            mx1 = max(mx1, r - l + 1)
            
        mx1 = max(mx1, n - l)

       
        # convert 'T' to 'F' to obtain the longest consecutive 'F' string
        l = 0
        remain = k
        mx2 = 0
        
        for r in range(n):
            if answerKey[r] == 'T':
                if remain:
                    remain -= 1
                else:
                    while answerKey[l] != 'T':
                        l += 1
                    l += 1
            mx2 = max(mx2, r - l + 1)
            
        mx2 = max(mx2, n - l)
        
        return max(mx1, mx2)
