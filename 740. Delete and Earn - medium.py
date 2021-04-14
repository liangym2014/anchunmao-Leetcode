"""
https://leetcode.com/problems/delete-and-earn/
"""

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        count = [(num, num * freq) for num, freq in Counter(nums).items()]
        count.sort(key = itemgetter(0))  # each element is a tuple (num, points)
        #print(count)
        
        acc = [count[0]]  # maximum points collected at step i
        
        if len(count) > 1:
            if count[1][0] - 1 > acc[-1][0]:
                acc.append((count[1][0], count[1][1] + acc[-1][1]))
            elif count[1][1] > count[0][1]:
                acc.append(count[1])
            else:
                acc.append(count[0])
                
                
        for i in range(2, len(count)):
            if count[i][0] - 1 > acc[-1][0]:
                acc.append((count[i][0], count[i][1] + acc[-1][1]))
            elif acc[-1][1] >= (count[i][1] + acc[-2][1]):
                acc.append(acc[-1])
            else:
                acc.append((count[i][0], count[i][1] + acc[-2][1]))
                
            acc.pop(0)  # only keep the result of the most recent two steps
                
        return acc[-1][1]
