# https://leetcode.com/problems/solving-questions-with-brainpower/
class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        max_val = [0] * n
        max_val[-1] = questions[-1][0]
        
        for i in range(-2, - n - 1, -1):
            point, step = questions[i]
            j = i + step + 1
            max_val[i] = max(max_val[i + 1], point + (max_val[j] if j < 0 else 0))

        return max_val[0]
