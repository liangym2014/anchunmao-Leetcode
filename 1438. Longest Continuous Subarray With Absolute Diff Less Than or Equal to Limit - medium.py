# https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        # keep the indices of elements that're larger than current element, elements sorted in descending order
        maxq = deque()
        # keep the indices of elements that're smaller than current element, elements sorted in ascending order
        minq = deque()

        start = 0  # start index of the subarray
        ans = 0
        
        for i, n in enumerate(nums):
            while maxq and n > nums[maxq[-1]]: 
                maxq.pop() #pop if elem is smaller
                
            maxq.append(i)                
                
            while minq and n < nums[minq[-1]]:
                minq.pop() #pop if elem is bigger

            minq.append(i)

            # maxq[0] is the maximum element, minq[0] is the smallest element
            if nums[maxq[0]]-nums[minq[0]] <= limit:
                continue
                
            ans = max(ans, i - start)
            
            while nums[maxq[0]]-nums[minq[0]] > limit:
                if maxq[0] == start:
                    maxq.popleft()
                    
                elif minq[0] == start: 
                    minq.popleft()
                    
                start += 1
            
        return max(ans, len(nums) - start)
