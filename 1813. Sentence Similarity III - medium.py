# https://leetcode.com/problems/sentence-similarity-iii/

class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        s1 = sentence1.split()
        s2 = sentence2.split()
        
        # make len(s1) <= len(s2)
        if len(s1) > len(s2):
            s1, s2 = s2, s1
        
        for k in range(2):
            i1 = 0
            i2 = 0

            while i2 < len(s2) and i1 < len(s1):
                if s2[i2] == s1[i1]:
                    i1 += 1
                else:
                    break
                i2 += 1

            if i1 == len(s1):
                return True

            s1 = list(reversed(s1[i1:]))
            s2 = list(reversed(s2[i2:]))

        return False
