// https://leetcode.com/problems/number-of-ways-to-select-buildings/
class Solution {
public:
    long long numberOfWays(string s) {
        // "010" and "101" are the qualified combinations
        long long c1 = 0, c2 = 0, c3 = 0, c4 = 0; // counters of "0", "1", "01", "10"
        long long ans = 0;
        
        for(auto &a: s){
            if(a == '0'){
                c4 += c2;    // update "10" counter
                ans += c3;  // update the number of "010" combination
                c1 ++;      // update "0" counter
            }
            else{
                c3 += c1;   // update "01" counter
                ans += c4;  // update the number of "101" combination
                c2 ++;      // update "1" counter
            }
        }
        return ans;
    }
};
