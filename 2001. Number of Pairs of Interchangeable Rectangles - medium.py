# https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/
class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        dt = Counter([(w / h) for w, h in rectangles])
        return sum([v * (v - 1) //2 for v in dt.values()])
