// https://leetcode.com/problems/count-the-hidden-sequences/
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mn = 0, mx = 0, cur = 0;
        for(auto &d : differences){
            cur += d;
            mn = min(mn, cur);
            mx = max(mx, cur);
        }
        
        if((mx - mn) > (upper - lower))
            return 0;
        
        return upper - (mx + (lower - mn)) + 1;
        
    }
};
