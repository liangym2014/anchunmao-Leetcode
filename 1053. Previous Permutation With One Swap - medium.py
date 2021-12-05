# https://leetcode.com/problems/previous-permutation-with-one-swap/
class Solution:
    def prevPermOpt1(self, arr: List[int]) -> List[int]:
        mn = arr[-1]
        dt = {}  # scanning arr from right to left, key: element in arr, value: the smallest index of the element

        for i in range(len(arr) - 1, -1, -1):
            if arr[i] <= mn:
                mn = arr[i]
                dt[arr[i]] = i
            else: # when arr[i] > mn, there's at least one element on the right of arr[i] could be swap with arr[i], thus reduce the permutation of arr
                keys = sorted(dt.keys())
                idx = bisect_left(keys, arr[i])  # swap arr[i] and the largest key in dt that's smaller than arr[i]
                swap_idx = dt[keys[idx - 1]]
                arr[i], arr[swap_idx] = arr[swap_idx], arr[i]
                break
                
        return arr
