# https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/

class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        frontier = {s}    # bfs frontier
        n = len(s)   # length of s
        entire = set()  # entire set of possible results
        
        while True:
            new_res = set()
            
            for elem in frontier:
                arr = list(elem)
                # rotation
                r = arr[-b:] + arr[:(n - b)]

                if "".join(r) not in entire:
                    new_res.add("".join(r))
            
                # addition
                for i in range(1,n,2):
                    arr[i] = ord(arr[i]) - 48 + a
                    if arr[i] > 9:
                        arr[i] -= 10

                    arr[i] = chr(arr[i] + 48)

                if "".join(arr) not in entire:
                    new_res.add("".join(arr))
    
            
            if not new_res: # if no new results generated from rotation or addition
                break
            else:
                entire |= (frontier | new_res)
                frontier = new_res
        

        entire = list(entire)
        entire.sort()
     
        return entire[0]
