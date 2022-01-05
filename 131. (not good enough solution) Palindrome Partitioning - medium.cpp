// https://leetcode.com/problems/palindrome-partitioning/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> cur(1, vector<string>({string(1,s[0])}));
        return f(s, cur, 1);
    }
    
    bool isPalindrome(string &s){
        for(int l = 0, r = s.size() - 1; l < r;){
            if(s[l ++] != s[r --])
                return false;
        }
        return true;
    }
    
    vector<vector<string>> f(string &s, vector<vector<string>> &prev, int i){
        if(i == s.size()){
            vector<vector<string>> cur;             
            for(auto &e: prev){
                if(isPalindrome(e.back()))
                    cur.push_back(e);
            }
            return cur;
        }
        
        int n = prev.size();
        string newstr = string(1, s[i]);
        for(int j = 0; j < n; j ++){
            if(isPalindrome(prev[j].back())){
                prev.push_back(prev[j]);
                prev.back().push_back(newstr);
            }
            
            prev[j].back().push_back(s[i]);
        }
        
        return f(s, prev, i + 1);
    }
};
