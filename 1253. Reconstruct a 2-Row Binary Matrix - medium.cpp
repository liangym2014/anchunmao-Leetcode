// https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/

#include <numeric>
#include <vector>

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size(), sum = accumulate(colsum.begin(), colsum.end(), 0);
        vector<vector<int>> ans(2, vector<int>(n));
        
        for(int i = 0; i < n; i ++){
            if(colsum[i] == 2){
                ans[0][i] = 1;
                ans[1][i] = 1;
                upper --;
                lower --;
                sum -= 2;
                
                if(upper < 0 || lower < 0)
                    return {};
            }
        }
        
        int i = 0;
        while(i < n && upper > 0 && sum > 0){
            if(colsum[i] == 1){
                ans[0][i] = 1;
                upper --;
                sum --;
            }
            
            ++ i;
        }        
        
        while(i < n && lower > 0 && sum > 0){
            if(colsum[i] == 1){
                ans[1][i] = 1;
                lower --;
                sum --;
            }
            
            ++ i;
        }
        
        if(upper == 0 && lower == 0 && sum == 0)
            return ans;
        
        return {};
    }
};
