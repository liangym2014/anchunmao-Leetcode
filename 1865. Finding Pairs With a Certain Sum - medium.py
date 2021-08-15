# https://leetcode.com/problems/finding-pairs-with-a-certain-sum/

class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1 = Counter(nums1)
        self.nums1 = [(key, val) for key, val in self.nums1.items()]
        self.nums1.sort(key = lambda x: x[0])
        
        self.nums2 = nums2
        self.max_nums2 = max(nums2)   # maximum of nums2
        self.count_nums2 = Counter(nums2)

    def add(self, index: int, val: int) -> None:
        old_val = self.nums2[index]   # value before addition
        self.nums2[index] += val      # value after addition
        
        # modify corresponding counts in self.count_nums2
        self.count_nums2[old_val] -= 1
        
        if self.count_nums2[old_val] == 0:
            self.count_nums2.pop(old_val)
        
        if self.nums2[index] in self.count_nums2:
            self.count_nums2[self.nums2[index]] += 1
        else:
            self.count_nums2[self.nums2[index]] = 1
        
        self.max_nums2 = max(self.max_nums2, self.nums2[index])
        

    def count(self, tot: int) -> int:
        # index of the first element in nums1 that could be part of the pair
        left = max(0, bisect_right(self.nums1, (tot - self.max_nums2,)) - 1)
        # index of the last element in nums1 that could be part of the pair
        right = bisect_right(self.nums1, (tot,)) - 1  
        ans = 0
        
        while right >= left:
            target = tot - self.nums1[right][0]
            if target in self.count_nums2:
                ans += self.nums1[right][1] * self.count_nums2[target]
                
            right -= 1

        return ans               
