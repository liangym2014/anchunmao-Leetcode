# https://leetcode.com/problems/number-of-people-aware-of-a-secret/
class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        arr = [0] * (n + 1)
        arr[1] = 1
        ans = 0
        
        for i in range(1, n + 1):
            if arr[i]:
                forget_date = i + forget
                for j in range(delay + i, min(forget_date, n + 1)):
                    arr[j] += arr[i]
                    
                if forget_date <= n:
                    ans -= arr[i]

        return (sum(arr) + ans) % 1000000007
