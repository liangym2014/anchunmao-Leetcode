/*
https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <algorithm>
using namespace std;

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode *cur = head;
        
        while(cur){
            n ++;
            cur = cur->next;
        }
        
        int mid = (n + 1) >> 1;
        
        //kth node is at the middle
        if((mid == k) && (n & 1))
            return head;
        
        //convert k to [1, mid]
        cur = head;

        if(k > mid)
            k = n - k + 1;
        
        int i = 1, first_k = k, last_k = n - k + 1;
        ListNode *first_k_node = NULL, *last_k_node = NULL;
        
        while(i != first_k){
            cur = cur->next;
            i ++;
        }
        
        first_k_node = cur;

        while(i != last_k){
            cur = cur->next;
            i ++;
        }
        
        last_k_node = cur;
        
        swap(first_k_node->val, last_k_node->val);
        return head;

    }
};
