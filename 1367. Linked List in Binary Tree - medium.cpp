// https://leetcode.com/problems/linked-list-in-binary-tree/
class Solution {
private:
    ListNode *head;

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        this->head = head;
        return dfs(root);
    }
    
    bool dfs(TreeNode* node){
        if(!node)
            return false;
        
        int cur = 0;
        
        if(head->val == node->val)
            cur = compare(head, node);
        
        if(cur == 1)
            return true;
        if(cur < 0)
            return false;

        bool l = dfs(node->left);
        if(l == true) return true;

        bool r = dfs(node->right);
        if(r == true) return true;

        return false; 
    }
    
    
    int compare(ListNode* list, TreeNode* node){
        if(!list) // downward path found
            return 1;
        
        if(!node)  // hit the leaf of the tree, not hit the end of the list 
            return -1;
        
        if(list->val != node->val)
            return 0;

        int l = compare(list->next, node->left);
        if(l == 1)  return 1;
        if(l < 0)   node->left = NULL;

        int r = compare(list->next, node->right);
        if(r == 1) return 1;
        if(r < 0)  node->right = NULL;
        
        if(l < 0 && r < 0)
            return -1;

        return 0;
    }
};
