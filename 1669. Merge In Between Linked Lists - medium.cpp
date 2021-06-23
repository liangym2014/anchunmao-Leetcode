// https://leetcode.com/problems/merge-in-between-linked-lists/

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *cur = list2;
        
        while(cur->next)
            cur = cur->next;
        
        ListNode *endb = cur;
        
        int i = 0, left_intersection = a - 1;
        cur = list1;
        
        while(i < left_intersection){
            cur = cur -> next;
            i ++;
        }
        
        ListNode *temp = cur->next;
        cur->next = list2;
        cur = temp;
        ++ i;

        while(i < b){
            cur = cur -> next;
            i ++;
        }
        
        endb->next = cur->next;
        return list1;
    }
};
