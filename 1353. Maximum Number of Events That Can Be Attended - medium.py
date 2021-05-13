# https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        current = []   # endDay of current envents
        events.sort(key = lambda x: x[0])   # sort based on asecending startDay
        # print("events:", events)
        
        ans = 0
        today = 1   # start from day 1
        i = 0     # index of the events
        
        # iterate if we hasn't looped through the events list, or if we still have current events not cleared from current list
        while current or i < len(events):
            # if no current event at today, and we still have unvisited events,
            # forward the date to the startDay of the next unvisited event
            if not current and i < len(events) and today < events[i][0]:
                today = events[i][0]
            
            # once an event is current, add it to current list
            while i < len(events) and today == events[i][0]:
                heappush(current, events[i][1])
                i += 1

            # pick the current event with earilest endDay to attend
            heappop(current)
            ans += 1
            
            # remove overdue events            
            while current and current[0] <= today:
                heappop(current)
                
            today += 1
       
        return ans
