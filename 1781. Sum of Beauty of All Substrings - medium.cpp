//https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
class Solution {
public:
    int beautySum(string s) {
        int sum = 0;

        for(int i = 0; i < s.size(); i ++){
            unordered_map<char, int> chars;
            
            for(int j = i; j < s.size(); j ++){
                chars[s[j]] ++;
                
                if(chars.size() > 1){
                    int mxf = 1, mnf = INT_MAX;
                    for(auto &e: chars){
                        mxf = max(mxf, e.second);
                        mnf = min(mnf, e.second);
                    }
                    sum += mxf - mnf;
                }
            }
            
            if(chars.size() == 1)
                break;
        }
        return sum;
    }
};
