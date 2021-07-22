// https://leetcode.com/problems/ways-to-make-a-fair-array/

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 1;
        
        if(n == 2)
            return 0;
        
        vector<int> oddSum(n), evenSum(n);
        oddSum[1] = nums[1];
        evenSum[0] = nums[0];
        evenSum[1] = nums[0];
        
        for(int i = 2; i < n; i ++){
            if(i & 1){
                oddSum[i] = oddSum[i - 1] + nums[i];
                evenSum[i] = evenSum[i - 1];
            }
            else{
                oddSum[i] = oddSum[i - 1];
                evenSum[i] = evenSum[i - 1] + nums[i];                
            }
        }
        
        int ans = 0, odd_index, even_index;
        
        // for index 0
        ans += (oddSum[n-1] == (evenSum[n-1] - evenSum[0]));


        for(int i = 1; i < n; i ++){
            if(i & 1){
                odd_index = oddSum[i - 1] + evenSum[n - 1] - evenSum[i - 1];
                even_index = evenSum[i - 1] + oddSum[n - 1] - oddSum[i];
            }
            else{
                odd_index = oddSum[i - 1] + evenSum[n - 1] - evenSum[i];
                even_index = evenSum[i - 2] + oddSum[n - 1] - oddSum[i - 1];
            }
            ans += (odd_index == even_index);
        }                    
        
        return ans;
    }
};
