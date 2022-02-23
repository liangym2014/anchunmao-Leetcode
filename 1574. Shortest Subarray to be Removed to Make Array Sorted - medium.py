# https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        # find the longest non-descending subarray starting with arr[0]
        l = n  # the size of the left subarray
        for i in range(1, n):
            if arr[i - 1] > arr[i]:
                l = i
                break
            
        if l == n:
            return 0
        
        # find the longest non-descending subarray ending with arr[-1]
        r = 1  # the size of the longest right subarray
        for i in range(n - 1, -1, -1):
            if arr[i - 1] > arr[i]:
                r = n - i
                break
        
        # find the longest non-descending array concatenated with arr[:i] + arr[j:]
        i = l - 1  # the last element of the left non-descending subarray
        j = n - r  # the first element of the right non-descending subarray
        if arr[i] <= arr[j]:
            return n - (l + r)
        
        pos = bisect_right(arr[:l], arr[j])
        concat = pos + r
        for i in range(pos, l):
            while j < n and arr[i] > arr[j]:
                j += 1
                
            if j == n:
                break
                
            concat = max(concat, n - (j - i - 1))

        return n - max(l, r, concat)
