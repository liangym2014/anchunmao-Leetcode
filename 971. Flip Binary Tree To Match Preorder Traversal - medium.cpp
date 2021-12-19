// https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/
class Solution {
private:
    vector<int> ans;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(root->val != voyage[0])
            return {-1};

        preorder(root, voyage, 1, voyage.size() - 1);
        return ans;
    }
    
    void preorder(TreeNode* root, vector<int>& voyage, int l, int r){
        if(!root->left && !root->right){
            if(l > r)
                return;
            
            ans = {-1};
            return;
        }
        
        if(l > r){
            ans = {-1};
            return;
        }

        if(!root->right){
            if(voyage[l] != root->left->val){
                ans = {-1};
                return;
            }
            
            preorder(root->left, voyage, l + 1, r);
            return;
        }
        
        if(!root->left){
            if(voyage[l] != root->right->val){
                ans = {-1};
                return;
            }
            
            preorder(root->right, voyage, l + 1, r);
            return;
        }
        
        int il, ir;
        int val = root->left->val;
        
        for(il = l; il <= r; ++ il){
            if(val == voyage[il])
                break;
        }

        if(il == (r + 1)){  // can't find the left child
            ans = {-1};
            return;
        }
        
        val = root->right->val;
        
        if(il == l){ // no flip
            for(ir = l + 1; ir <= r; ir ++){
                if(val == voyage[ir])
                    break;
            }
            
            if(ir == (r + 1)){ // can't find the right child
                ans = {-1};
                return;
            }
            
            preorder(root->left, voyage, l + 1, ir - 1);
            
            if(!ans.empty() && ans.front() < 0){
                ans = {-1};
                return;
            }
            
            preorder(root->right, voyage, ir + 1, r);
            
            if(!ans.empty() && ans.front() < 0){
                ans = {-1};
                return;
            }
         
        }
        else{// flip
            if(voyage[l] != val){ // can't find the right child
                ans = {-1};
                return;
            }
            
            preorder(root->left, voyage, il + 1, r);
            
            if(!ans.empty() && ans.front() < 0){
                ans = {-1};
                return;
            }
            
            preorder(root->right, voyage, l + 1, il - 1);
            
            if(!ans.empty() && ans.front() < 0){
                ans = {-1};
                return;
            }
            
            ans.push_back(root->val);
        }
   
    }
};
