# https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        n = 1
        cur = head.next
        
        while cur:
            n += 1
            cur = cur.next
        
        if n == 1:
            return None
        
        stop = n // 2 - 1
        cur = head
        
        while stop:
            stop -= 1
            cur = cur.next
            
        cur.next = cur.next.next
        return head
