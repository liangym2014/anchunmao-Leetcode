// https://leetcode.com/problems/distribute-coins-in-binary-tree/
class Solution {
private:
    int moves = 0;
public:
    int distributeCoins(TreeNode* root) {
        traverse(root);
        return moves;
    }
    
    int traverse(TreeNode* root){
        if(!root)
            return 0;
        
        // at the root node:
        // subtree returns positive value: the moves of redundant coins in this subtree made to reach root;
        // subtree returns negative value: the moves of missing coins in this subtree made to reach root.
        int l = traverse(root->left), r = traverse(root->right);
        moves += abs(l) + abs(r);
        return l + r + (root->val - 1);

    }
};
