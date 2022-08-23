# https://leetcode.com/problems/count-number-of-ways-to-place-houses/
class Solution:
    def countHousePlacements(self, n: int) -> int:
        M = 1000000007
        
        # Only consider the n plots on one side of the street. Treat them as
        # a list of length n. Set ith element as 1 is equal to place a house at ith plot.
        
        # if set arr[i] as 1, arr[i - 1] must be set to 0. So the number of ways to set arr[i] as 1
        # is equal to the number of ways to set arr[i - 1] as 0.
        
        # if set arr[i] as 0, arr[i - 1] could be either 0 or 1. So the number of ways to set arr[i] as 0
        # is equal to the number of ways to (set arr[i - 1] as 0 + set arr[i - 1] as 1).
        
        # only one way to set arr[1] as 0, and one way to set arr[1] as 1
        set0 = 1
        set1 = 1
        for i in range(2, n + 1):
            set0 %= M
            set0, set1 = (set0 + set1), set0
            
        total = (set0 + set1) % M  # the ways to arrange one side of the street
        return total**2 % M   # the ways to arrange both sides of the street is total * total
