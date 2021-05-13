# https://leetcode.com/problems/sort-integers-by-the-power-value/

class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        dt = defaultdict(list)
        
        for num in range(lo, hi + 1):
            power = self.get_power(num)
            dt[power].append(num)
            
        arr = list(dt.items())
        arr.sort(key = lambda x: x[0])
        # print(arr)
        count = 0
        
        for _, vals in arr:
            if len(vals) + count < k:
                count += len(vals)
            else:
                return vals[k - count - 1]
            
    def get_power(self, num):
        acc = 0
        
        while num > 1:
            if num & 1:
                num = num * 3 + 1
            else:
                num >>= 1
            acc += 1
            
        return acc
