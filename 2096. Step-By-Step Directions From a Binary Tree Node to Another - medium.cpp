// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
class Tree{
private:
    string start_path, end_path;
    int num_nodes_found = 0;
    
public:
    void search_nodes(TreeNode* root, int &startValue, int &destValue, string &path){
        if(!root)
            return;
        
        if(root->val == startValue){
            start_path = path;
            ++ num_nodes_found;
        }
        if(root->val == destValue){
            end_path = path;
            ++ num_nodes_found;
        }
        
        if(num_nodes_found == 2)
            return;
        
        path.push_back('L');
        search_nodes(root->left, startValue, destValue, path);
        path.pop_back();
        
        if(num_nodes_found == 2)
            return;

        path.push_back('R');        
        search_nodes(root->right, startValue, destValue, path);
        path.pop_back();
    }
    
    string merge_paths(){
        int i = 0, min_len = min(start_path.size(), end_path.size());
        for(; i < min_len; i ++){
            if(start_path[i] != end_path[i]) // this is the common ancestor
                break;
        }
        
        return string(start_path.size() - i, 'U') + end_path.substr(i);
    }
};

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        Tree t;
        string path = "";
        t.search_nodes(root, startValue, destValue, path);
        return t.merge_paths();
    }
};
