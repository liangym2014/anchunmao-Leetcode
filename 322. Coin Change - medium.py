'''
https://leetcode.com/problems/coin-change/
'''

class Solution:
    #'''
    #solution 1:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
            
        if amount < min(coins):
            return -1
        
        MAX = 100000
        dp = [MAX] * (amount + 1)
        dp[0] = 0

        for coin in coins:
            if coin > amount:
                continue
                
            for j in range(coin, len(dp)):
                dp[j] = min(dp[j], 1 + dp[j - coin])

        return dp[-1] if dp[-1] != MAX else -1
    #'''
    
    
    '''
    #solution 2:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        
        if amount < min(coins):
            return -1
        
        MAX = 100000
        dp = [MAX] * (amount + 1)
        dp[0] = 0

        for j in range(len(dp)):
            for coin in coins:
                if coin > amount:
                    continue 
                dp[j] = min(dp[j], 1 + dp[j - coin])

        return dp[-1] if dp[-1] != MAX else -1
    '''
