# https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        mndist = inf
        prev_point_idx, first_point_idx = -1, -1
        
        i = 2
        prev, cur = head.val, head.next
        
        while cur.next:
            if (cur.val - prev) * (cur.val - cur.next.val) > 0:
                if prev_point_idx >= 0:
                    dist = i - prev_point_idx
                    mndist = min(mndist, dist)
                else:
                    first_point_idx = i
                    
                prev_point_idx = i
                
            i += 1
            prev = cur.val
            cur = cur.next
            
        return [mndist, prev_point_idx - first_point_idx] if mndist != inf else [-1, -1]
