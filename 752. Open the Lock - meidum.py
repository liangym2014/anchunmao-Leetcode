# https://leetcode.com/problems/open-the-lock/
import queue
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        if target == "0000":
            return 0

        deadends = set(deadends)
        if "0000" in deadends:
            return -1
        deadends.add("0000")
        
        q = queue.Queue()
        q.put("0000")
        
        turns = 0
        
        while q.qsize():
            n = q.qsize()

            while n:
                num = q.get()
                n -= 1

                for i in range(4):
                    high = num[:i] + ("0" if num[i] == '9' else chr(ord(num[i]) + 1)) + num[i + 1:]
                    low = num[:i] + ("9" if num[i] == '0' else chr(ord(num[i]) - 1)) + num[i + 1:]
                    
                    if target in (high, low):
                        return turns + 1
                    
                    if high not in deadends:
                        q.put(high)
                        deadends.add(high)
                        
                    if low not in deadends:
                        q.put(low)
                        deadends.add(low)
        
            turns += 1
            
        return -1
