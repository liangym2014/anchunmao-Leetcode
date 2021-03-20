/*
https://leetcode.com/problems/add-one-row-to-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1)
            return new TreeNode(v, root, NULL);
        
        int parent_depth = d - 1;
        addNode(root, v, parent_depth, 1);
        return root;
    }
    
    void addNode(TreeNode* root, int& v, int& parent_depth, int d){
        if(!root)   return;
        
        if(d == parent_depth){
            TreeNode *newleft = new TreeNode(v, root->left, NULL);
            TreeNode *newright = new TreeNode(v, NULL, root->right);
            root->left = newleft;
            root->right = newright;
            return;
        }

        addNode(root->left, v, parent_depth, d + 1);
        addNode(root->right, v, parent_depth, d + 1);        
    }
};
