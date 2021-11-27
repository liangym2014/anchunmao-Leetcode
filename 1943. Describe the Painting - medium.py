# https://leetcode.com/problems/describe-the-painting/

class Solution:
    def splitPainting(self, segments: List[List[int]]) -> List[List[int]]:
        numberline = defaultdict(int)
        for start, end, color in segments:
            numberline[start] += color
            numberline[end] -= color

        numberline = list(numberline.items())
        numberline.sort(key = lambda x: x[0])
        
        mix = 0  # the sum of mixed colors
        ans = []
        start = -1
        for coord, color in numberline:
            if mix:
                ans.append([start, coord, mix])
            mix += color
            start = coord

        return ans
