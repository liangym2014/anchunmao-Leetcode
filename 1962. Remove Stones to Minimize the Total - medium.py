# https://leetcode.com/problems/remove-stones-to-minimize-the-total/

class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        piles = [-x for x in piles]
        heapify(piles)

        # each time pick the one with the maximum absolute value and  halve it
        for i in range(k):
            ele = -heappop(piles)  # convert to positive, which is the maximum element in piles

            if ele == 1:
                piles.append(-1)
                break
            ele -= floor(ele/2)

            heappush(piles, -ele)

        return -sum(piles)
