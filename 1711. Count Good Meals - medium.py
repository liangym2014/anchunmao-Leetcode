# https://leetcode.com/problems/count-good-meals/submissions/
modul = 1000000007

class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        limit = 2 * max(deliciousness)
        
        power2 = [2**i for i in range(22) if 2**i <= limit]
        m = Counter(deliciousness)
        ans = 0
        
        for k, v in m.items():
            l = bisect_left(power2, k)
            
            for i in range(l, len(power2)):
                p = power2[i] - k
                    
                if p in m:
                    ans += (v * v - v) if k == p else (m[p] * v)
                   
        return (ans >> 1) % modul
