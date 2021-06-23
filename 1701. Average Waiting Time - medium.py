# https://leetcode.com/problems/average-waiting-time/

class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        wait_time = 0   # total waiting time
        end_time = 0   # the time the chef finishes the last order
        
        for arrival, time in customers:
            # if end_time > arrival, the waiting time for current customer will be end_time - arrival + time
            if end_time > arrival:
                wait_time += end_time - arrival + time
                end_time += time
            else:
                wait_time += time
                end_time = arrival + time
            
        return wait_time / len(customers)
