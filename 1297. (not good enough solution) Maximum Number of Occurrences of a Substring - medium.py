# https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        dt = defaultdict(int)  # count the number of substrings, key: substring, value: count
        n = len(s)
        
        for i in range(n - minSize + 1):
            substr = s[i:i + minSize]
            m = set(list(substr))
            if len(m) > maxLetters:
                continue
                
            dt[substr] += 1
            l = min(i + maxSize, n)
            
            for j in range(i + minSize, l):
                m.add(s[j])
                if len(m) <= maxLetters:
                    substr += s[j]
                    dt[substr] += 1
                else:
                    break
        
        # print(dt)
        if len(dt) == 0:
            return 0
        return sorted(set(dt.values()))[-1]
