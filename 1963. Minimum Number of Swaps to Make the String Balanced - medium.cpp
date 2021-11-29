// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

class Solution {
public:
    int minSwaps(string s) {
        int opens = 0;
        for(auto &e: s){
            if(e == '['){
                opens ++;
            }
            else if(opens > 0)
                opens --;
        }
        return (opens >> 1) + (opens & 1);
    }
};
