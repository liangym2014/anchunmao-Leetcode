# https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        ans = 0
        unique_chars = Counter(list(s))
        
        for v in unique_chars.values():
            if v + k >= len(s):
                return len(s)
                    
        for c in unique_chars.keys():
            acc = 0  # the number of char c in s[0:i]
            dt = {}  # key: acc - (index of 1st occurrence of acc), value: index of 1st occurrence of such key
            dt[1] = -1  # corresponding to acc = 0 and index = -1
            
            # suppose accj at s[j] and acci at s[i], for s[j + 1: i], if convert all other letters into char c:
            # i - j = acci - accj + k ==> accj - j = acci - i + k
            for i, ele in enumerate(s):
                if ele == c:
                    acc += 1
                    
                cur_key = acc - i
                
                if i + 1 > ans:
                    prev_key = cur_key + k

                    if prev_key in dt:
                        ans = max(ans, i - dt[prev_key])

                if cur_key not in dt:
                    dt[cur_key] = i
                        
        return ans
