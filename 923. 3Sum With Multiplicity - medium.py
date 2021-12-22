# https://leetcode.com/problems/3sum-with-multiplicity/
modulo = 1000000007

class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        arr = sorted(list(Counter(arr).items()), key = lambda x: x[0])
        keys, vals = zip(*arr)
        ans = 0
        
        for i in range(len(keys)):
            if (3 * keys[i]) > target:
                break
            
            # target = 3 * keys[i]
            if vals[i] >=3 and (keys[i] * 3) == target:
                ans += vals[i] * (vals[i] - 1) * (vals[i] - 2) // 6
   
            
            # target = 2 * keys[i] + keys[idx]
            if vals[i] >= 2:
                k = target - 2 * keys[i]
                idx = bisect_left(keys, k, i + 1)
                if idx != len(keys) and keys[idx] == k:
                    ans += vals[i] * (vals[i] - 1) // 2 * vals[idx]

                    
            # target = keys[i] + 2 * keys[idx]
            if ((target - keys[i]) & 1) == 0:
                k = (target - keys[i]) >> 1
                idx = bisect_left(keys, k, i + 1)
                if idx != len(keys) and keys[idx] == k and vals[idx] >= 2:
                    ans +=  vals[i] * vals[idx] * (vals[idx] - 1) // 2

            
            # target = keys[i] + keys[j] + keys[idx]
            for j in range(i + 1, len(keys)):
                k = target - keys[i] - keys[j]
                if k <= keys[j]:
                    break

                idx = bisect_left(keys, k, j + 1)
                if idx != len(keys) and keys[idx] == k:
                    ans += vals[i] * vals[j] * vals[idx]

        return ans % modulo
