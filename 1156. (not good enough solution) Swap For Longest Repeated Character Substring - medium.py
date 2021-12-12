# https://leetcode.com/problems/swap-for-longest-repeated-character-substring/
class Solution:
    def maxRepOpt1(self, text: str) -> int:
        count = Counter(text)
        
        if len(count) == 1:
            return len(text)
        
        l, ans = 0, 1
        acc = defaultdict(int)
        
        for i in range(len(text)):
            acc[text[i]] += 1
            
            if len(acc) == 1 or (i - l + 1) <= ans:
                continue

            while len(acc) > 2:
                if acc[text[l]] == 1:
                    acc.pop(text[l])
                else:
                    acc[text[l]] -= 1

                l += 1

            if (i - l + 1) <= ans:
                continue

            k1, k2 = acc.keys()
            v1, v2 = acc.values()
            t1, t2 = count[k1], count[k2]

            while v1 and v2 and (i - l + 1) > ans:
                if (v1 == 1 and t2 > v2) or (v2 == 1 and t1 > v1):
                    ans = i - l + 1
                    break

                if text[l] == k1:
                    v1 -= 1
                else:
                    v2 -= 1

                l += 1
            
            if v1:
                acc[k1] = v1
            else:
                acc.pop(k1)
                
            if v2:
                acc[k2] = v2
            else:
                acc.pop(k2)
                
        return ans      
