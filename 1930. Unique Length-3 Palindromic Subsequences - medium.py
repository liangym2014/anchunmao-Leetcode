# https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        if len(s) == 3:
            return int(s[0] == s[-1])
        
        # number of unique letters in s 
        num_chars = 26        
        # choice for center char is num_chars, choice for first/last char is also num_chars
        # so the maximum number of subsequences is num_chars * num_chars
        max_num_subsequence = num_chars * num_chars
        # all num_chars bits are set
        max_set_bits = int('1'* num_chars, 2)

        lr = []
        # acc is a num_chars-bit integer. 
        # traversing s from left to right, if ith character appears, set ith bit in acc to 1
        acc = (1 << (ord(s[0]) - 97))
        lr.append(acc)
        
        for c in s[1:]:
            acc |= (1 << (ord(c) - 97))
            lr.append(acc)
            
            if acc == max_set_bits:
                lr += [acc] * (len(s) - len(lr))
                break
                
        # racc is a num_chars-bit integer. 
        # traversing s from right to left, if ith character appears, set ith bit in racc to 1                
        racc = (1 << (ord(s[-1]) - 97))
        
        # each element in center_char is a num_chars-bit integer that represents palindromes of length 3
        # centering at char 'a' - 'z' correspondingly. for ith element, if its jth bit is set, 
        # that means the palindrome of chr(97 + j) + chr(97 + i) + chr(97 + j) exists in s.
        center_char = [0] * num_chars  
        ans = 0
        
        for i in range(len(s) - 2, 0, -1):
            # compare the bits set on the left and on the right of s[i], when the same bit is set in both
            # lr[i - 1] and racc, it generates a palindromic subsequence
            comparison = lr[i - 1] & racc
            element_idx = ord(s[i]) - 97  # index of s[i] in center_char
            
            # if the set bits in comparison are already set in center_char[element_idx], no action needed.
            # otherwise, the new palindromes are constructed by s[i] and the new set bits in comparison, and
            # the new set bits in comparison need to be set in center_char[element_idx].
            res = center_char[element_idx] | comparison
            
            if res != center_char[element_idx]:
                res ^= center_char[element_idx]
                j = 0
                while res:
                    if res & 1:
                        center_char[element_idx] |= (1<< j)
                        ans += 1

                    res >>= 1
                    j += 1
         
            racc |= (1 << element_idx)

            if ans == max_num_subsequence:  # if ans reaches the maximum number of subsequences, exit
                break
                
        return ans
