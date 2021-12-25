# https://leetcode.com/problems/find-original-array-from-doubled-array/
class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        original = []
        
        if len(changed) & 1:
            return original
        
        dt = Counter(changed)
        odd_keys = [k for k in dt.keys() if k & 1]
        
        # each odd key should have a corresponding even key
        for key in odd_keys:
            double_key = key << 1
            
            if double_key in dt and dt[double_key] >= dt[key]:
                original.extend([key] * dt[key])
                dt[double_key] -= dt[key]
                dt.pop(key)

                if not dt[double_key]:
                    dt.pop(double_key)
            else:
                return []
        
        if not dt:
            return original

        
        # go through even keys in ascending order
        if 0 in dt:
            if dt[0] & 1:
                return []
            else:
                original.extend([0] * (dt[0] >> 1))
                dt.pop(0)
            
        even_keys = sorted(dt.keys())

        for key in even_keys:
            if key not in dt:
                continue
                
            double_key = key << 1
            
            if double_key in dt and dt[double_key] >= dt[key]:
                original.extend([key] * dt[key])
                dt[double_key] -= dt[key]
                dt.pop(key)

                if not dt[double_key]:
                    dt.pop(double_key)
            else:
                return []
            
        return original
