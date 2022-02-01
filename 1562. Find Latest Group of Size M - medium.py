# https://leetcode.com/problems/find-latest-group-of-size-m/
class Solution:
    def findLatestStep(self, arr: List[int], m: int) -> int:
        n = len(arr)
        if m == n:
            return n
        
        dt = defaultdict(int) # key: the length of contiguous substring of 1, val: count
        v = [0] * (2 + n)
        ans = -1
        
        for step, num in enumerate(arr):
            prev = num - 1
            nxt = num + 1

            if v[prev]:
                dt[v[prev]] -= 1
                if dt[v[prev]] == 0:
                    dt.pop(v[prev])
                    
            if v[nxt]:
                dt[v[nxt]] -= 1
                if dt[v[nxt]] == 0:
                    dt.pop(v[nxt])

            val = 1 + v[prev] + v[nxt]
            v[num - v[prev]], v[num], v[v[nxt] + num] = val, val, val                        

            dt[val] += 1
                
            if m in dt:
                ans = step
            
        return ans if ans < 0 else (ans + 1)
