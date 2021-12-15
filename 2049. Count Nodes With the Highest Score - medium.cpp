// https://leetcode.com/problems/count-nodes-with-the-highest-score/
class Solution {
private:
    long long score; // keep the highest score
    vector<vector<int>> children;
    int n; // the number of nodes in the tree
    int count = 0;  // the number of nodes achieving the highest score
    
public:
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        children = vector<vector<int>>(n);
        
        for(int i = 1; i < n; i ++){
            children[parents[i]].push_back(i);
        }

        traverse(0);
        return count;
    }
    
    int traverse(int root){
        if(children[root].empty()){
            update_score_count(n - 1);
            return 1;
        }
        
        if(children[root].size() == 2){
            int l = traverse(children[root][0]), r = traverse(children[root][1]);
            update_score_count((long long)l * r * (n - l - r - (root != 0)));
            return l + r + 1;
        }
        
        int l = traverse(children[root][0]);
        update_score_count((long long)l * (n - l - (root != 0)));
        return l + 1;
    }
               
               
    void update_score_count(long long new_score){
        if(new_score == score)
            count ++;
        else if(new_score > score){
            score = new_score;
            count = 1;
        }
    }
    
};
