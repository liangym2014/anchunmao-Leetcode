# https://leetcode.com/problems/array-of-doubled-pairs/
class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        m = Counter(arr)
        if 0 in m:
            if m[0] & 1:
                return False
            else:
                m.pop(0)

        for k in sorted(m.keys(), key = lambda x: abs(x)):
            if k not in m:
                continue
            key = 2 * k
            v = m[k]
            if key not in m or m[key] < v:
                return False

            if m[key] > v:
                m[key] -= v
            else:
                m.pop(key)

        return True
