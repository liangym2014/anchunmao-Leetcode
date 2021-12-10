# https://leetcode.com/problems/reverse-nodes-in-even-length-groups/
class Solution:
    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]:
        section_id = 2  # total number of groups
        cur = head.next
        count = 0  # number of elements in the last group
        
        while cur:
            if count < section_id:
                count += 1
            else:
                section_id += 1
                count = 1
                
            cur = cur.next
            
        if section_id == 2 and count < 2:
            return head
        
        last_section_reverse = False # flag whether the last group needs to be reversed
        if (count & 1) == 0: # the length of last section is even
            last_section_reverse = True
            

        cur = head.next
        section_count = 2  # the id of current group
        i = 1
        prev = head  # the element ahead of the 1st element in an even-length group
        
        lim = (section_id - 2) if (section_id & 1) == 0 and not last_section_reverse else (section_id - 1)
            
        while section_count <= lim:
            if (section_count & 1) == 0:  # if current group is even-length
                end = cur
                left = cur  # mark the element on the left
                cur = cur.next

                while i < section_count:
                    i += 1
                    right = cur.next
                    cur.next = left  # make cur -> left
                    left = cur
                    cur = right
                    
                # when it comes to the end of even group, connect prev -> left ->....-> end -> right
                prev.next = left
                end.next = cur
                cur = end
     
            else:    # if current group is odd-length
                while i < section_count:
                    i += 1
                    cur = cur.next

                # if current group is odd-length, mark the last element in current group as prev, 
                # which will connect to the last element of the next even group    
                prev = cur
                
            # start a new group
            section_count += 1
            i = 1
            cur = cur.next                

                
        if last_section_reverse:
            # if the second to last group is even-length,
            # mark the last element in the second to last group as prev
            if (section_id & 1):
                prev = end
                
            end = cur
            left = cur
            cur = cur.next

            while cur:
                right = cur.next
                cur.next = left
                left = cur
                cur = right

            prev.next = left
            end.next = None
            
        return head   
