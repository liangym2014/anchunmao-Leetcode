# https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        if (3 * 2**(n - 1)) < k:
            return ""

        self.n = n
        self.k = k
        count = 0
        for c in ['a', 'b', 'c']:
            happy_str, count = self.generate_strings(c, count)

            if count == k:
                return happy_str

        
    def generate_strings(self, prev, count):
        if len(prev) == self.n:
            return prev, count + 1
        
        if prev[-1] == 'a':
            left = 'b'
            right = 'c'
        elif prev[-1] == 'b':
            left = 'a'
            right = 'c'
        else:
            left = 'a'
            right = 'b'
        
        happy_str, count = self.generate_strings(prev + left, count)
        if count == self.k:
            return happy_str, count

        happy_str, count = self.generate_strings(prev + right, count)
        return happy_str, count
