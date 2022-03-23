//https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        for(int i = 0; i < s.size(); i ++){
            for(int j = 0; j < t.size(); j ++){
                ans += f(s, t, i, j);
            }
        }
        return ans;
    }
    
    int f(string &s, string &t, int i, int j){
        int res = 0;
        while(i < s.size() && j < t.size()){
            if(s[i] != t[j]){
                if(res == 0)
                    res = 1;
                else
                    break;
            }
            else if(res > 0)
                res ++;
            ++ i;
            ++ j;
        }
        return res;
    }
};
