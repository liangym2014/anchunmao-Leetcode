# https://leetcode.com/problems/count-artifacts-that-can-be-extracted/
class Solution:
    def digArtifacts(self, n: int, artifacts: List[List[int]], dig: List[List[int]]) -> int:
        dig_area = defaultdict(set)
        for r, c in dig:
            dig_area[r].add(c)
            
        res = 0
        for r1, c1, r2, c2 in artifacts:
            extract = True
            for r in range(r1, r2 + 1):
                for c in range(c1, c2 + 1):
                    if r not in dig_area or c not in dig_area[r]:
                        extract = False
                        break
                        
                if not extract:
                    break
                    
            res += int(extract)
            
        return res
