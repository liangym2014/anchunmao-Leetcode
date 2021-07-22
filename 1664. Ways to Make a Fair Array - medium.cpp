// https://leetcode.com/problems/ways-to-make-a-fair-array/

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 1;
        
        if(n == 2)
            return 0;
        
        vector<int> sum(n);
        sum[0] = nums[0];
        sum[1] = nums[1];
        
        for(int i = 2; i < n; i ++)
            sum[i] = sum[i - 2] + nums[i];

        int oddSum = sum.back(), evenSum = sum[n - 2];
        
        if(n & 1)
            swap(oddSum, evenSum);

        int ans = 0, odd_index, even_index;
        
        // for index 0
        ans += (oddSum == (evenSum - sum[0]));

        // for index 1
        odd_index = evenSum - sum[0];
        even_index = sum[0] + oddSum - sum[1];
        ans += (odd_index == even_index);

        for(int i = 2; i < n; i ++){
            if(i & 1){
                odd_index = sum[i - 2] + evenSum - sum[i - 1];
                even_index = sum[i - 1] + oddSum - sum[i];
            }
            else{
                odd_index = sum[i - 1] + evenSum - sum[i];
                even_index = sum[i - 2] + oddSum - sum[i - 1];
            }
            ans += (odd_index == even_index);
        }                    
        
        return ans;
    }
};
