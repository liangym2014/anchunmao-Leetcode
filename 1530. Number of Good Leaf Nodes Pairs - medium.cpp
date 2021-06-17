//https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

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
private:
    vector<pair<unsigned long, int>> leaf;  //{val, depth}
public:
    int countPairs(TreeNode* root, int distance) {
        dfs(root, 1, 1);
        
        if(leaf.size() == 1)  // only one leaf node, no pairs exist
            return 0;
        
        int ans = 0;
        
        for(int i = 0; i < leaf.size(); ++ i){
            for(int j = i + 1; j < leaf.size(); ++ j){
                int dist = 0;  // the shortest path between leaf[i] and leaf[j]
                
                if(leaf[i].second > leaf[j].second){
                    // align two leaf values on the left
                    unsigned long j_val = leaf[j].first <<(leaf[i].second - leaf[j].second);
                    // get the position of the most significant bit in leaf[i].val xor leaf[j].val,
                    // from where the two paths leading to leaf[i] and leaf[j] differ.
                    int num_bits = num_binarybits(leaf[i].first ^ j_val);
                    // shortest path between the two leaves = path from differ position to leaf[i] + 
                    // path from differ position to leaf[j] 
                    dist = num_bits + leaf[j].second - (leaf[i].second - num_bits);
                }
                else if(leaf[i].second < leaf[j].second){
                    unsigned long i_val = leaf[i].first <<(leaf[j].second - leaf[i].second);
                    int num_bits = num_binarybits(leaf[j].first ^ i_val);
                    dist = num_bits + leaf[i].second - (leaf[j].second - num_bits);
                }
                else{
                    int num_bits = num_binarybits(leaf[i].first ^ leaf[j].first);
                    dist = 2 * num_bits;                    
                }
                
                if(dist <= distance)
                    ans ++;                
            }
        }
        
        return ans;
    }
    
    void dfs(TreeNode* root, unsigned long val, int depth){
        if(!root)
            return;
        
        if(!root->left && !root->right){  //leaf node
            leaf.push_back({val, depth});
            return;
        }
        
        dfs(root->left, ((val << 1) | 1), depth + 1);
        dfs(root->right, (val << 1), depth + 1);    
    }
    
    int num_binarybits(unsigned long num){
        // get the position of the most significant bit in num
        int res = 0;
        while(num){
            num >>= 1;
            res ++;
        }
        return res;
    }
};
