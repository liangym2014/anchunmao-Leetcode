# https://leetcode.com/problems/adding-spaces-to-a-string/
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans = s[:spaces[0]] + ' '
        n = len(spaces)
        
        for i in range(1, n):
            ans += s[spaces[i - 1]: spaces[i]] + ' '

        return ans + s[spaces[-1]:]
