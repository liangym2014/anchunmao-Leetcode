# https://leetcode.com/problems/find-the-winner-of-an-array-game/

class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        i = 0
        
        while 1:
            # if i > 0, arr[i] must win by once when compared with its predecessors.                
            wins = 1 if i else 0  
            j = i + 1
            
            # compare arr[i] to elements after it
            while j < len(arr):
                if arr[i] < arr[j]:  # arr[i] fails before reaching k consecutive success, stop comparing.
                    if k == 1:
                        return arr[j]                    
                    break
                    
                # so far, arr[i] is the max element. Continue comparing with the remaining elements
                # until it reaches k consecutive success.
                wins += 1                   
                if wins == k:
                    return arr[i]

                j += 1
            

            if j == len(arr):
                # since all elements prior to and after arr[i] are less than arr[i],
                # arr[i] is the maximum among the list. It must be the winner.
                return arr[i]
            else:   
                # elements between arr[i] and arr[j] are less than both of them. 
                # These elements should be placed at the end of the list. skip them.
                i = j
