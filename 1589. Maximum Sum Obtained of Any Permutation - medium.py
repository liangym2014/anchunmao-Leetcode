# https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/
M = 1000000007
class Solution:
    def maxSumRangeQuery(self, nums: List[int], requests: List[List[int]]) -> int:
        m = defaultdict(int)  # key: occurrence, value: number of elements
        if len(requests) == 1:
            m[1] = requests[0][1] - requests[0][0] + 1
        else:
            idx = [0] * (len(nums) + 1)

            for r in requests:
                start, end = r
                idx[start] += 1
                idx[end + 1] += -1

            acc = 0
            for i in idx:
                acc += i
                if acc:
                    m[acc] += 1
                
        # sort in the order of elements occurring more frequently to less frequently        
        order = sorted(m.items(), key = lambda x: -x[0])
        nums.sort(reverse = True)   # large elements are placed ahead
        start = 0
        res = 0

        for occur, num_elements in order:
            res += sum(nums[start: start + num_elements]) * occur
            res %= M
            start += num_elements
            
        return res   
