# https://leetcode.com/problems/merge-nodes-in-between-zeros/
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        acc = head.next
        head = acc
        cur = acc.next
        while cur:
            if cur.val:
                acc.val += cur.val
                cur = cur.next
            else:
                cur = cur.next
                acc.next = cur
                acc = cur
                if acc:
                    cur = acc.next

        return head
