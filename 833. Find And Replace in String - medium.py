# https://leetcode.com/problems/find-and-replace-in-string/
class Solution:
    def findReplaceString(self, s: str, indices: List[int], sources: List[str], targets: List[str]) -> str:
        replacement = list(zip(indices, sources, targets))
        replacement.sort(key = lambda x: x[0])
        n = len(replacement)
        l = len(s)
        ans = s[:replacement[0][0]]
        
        for i in range(n - 1):
            idx, source, target = replacement[i]
            end_of_source = idx + len(source)
            
            if end_of_source >= l or s[idx: end_of_source] != source:
                ans += s[idx : replacement[i + 1][0]]
            else:
                ans += target + s[end_of_source : replacement[i + 1][0]]

            
        idx, source, target = replacement[-1]
        end_of_source = idx + len(source)

        if end_of_source > l or s[idx: end_of_source] != source:
            ans += s[idx : ]
        else:
            ans += target + s[end_of_source : ]
            
        return ans
