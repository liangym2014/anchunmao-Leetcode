'''
https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
'''

class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        """
        1. compute the maximum ASCII sum of the common subsequence between s1 and s2.
        2. get the lowest ASCII sum of deleted chars by subtracting this maximum sum from s1 and s2.
        """        
        l1 = len(s1)
        l2 = len(s2)

        # j == 0
        idx = s1.find(s2[0])
        
        # prev: the maximum sum of the common subsequence between s1[0:i] and s2[0:(j - 1)]
        if idx == -1:
            prev = [0] * l1
        else:
            prev = [0] * idx + [ord(s2[0])] * (l1 - idx)
 
               
        # j > 0                
        for j in range(1, l2):
            cur = [0] * l1  # the maximum sum of the common subsequence between s1[0:i] and s2[0:j]
            
            for i in range(l1):
                if s2[j] == s1[i]:
                    cur[i] = max(prev[i - 1] + ord(s1[i]), prev[i], cur[i - 1]) if i else ord(s1[i])
                else:
                    cur[i] = max(cur[i - 1], prev[i]) if i else prev[0]
                        
            prev = cur
                    
        sum_1 = sum([ord(x) for x in s1])
        sum_2 = sum([ord(x) for x in s2])
        
        return sum_1 + sum_2 - 2 * prev[-1] 
