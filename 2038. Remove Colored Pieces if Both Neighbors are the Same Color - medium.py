# https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        counta, countb = 0, 0
        a, b = 0, 0
        
        for c in colors:
            if c == 'A':
                counta += 1
                
                if countb:
                    if countb > 2:
                        b += (countb - 2)
                    countb = 0
                    
            else: # c == 'B'
                countb += 1
                
                if counta:
                    if counta > 2:
                        a += (counta - 2)
                    counta = 0
                    
        if counta > 2:
            a += (counta - 2)
            
        if countb > 2:
            b += (countb - 2)
    
        return a > b
