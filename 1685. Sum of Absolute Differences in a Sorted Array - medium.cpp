// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> acc(n); 
        
        for(int i = 1; i < n; i ++){
            acc[i] = acc[i - 1] + nums[i] - nums[0]; 
        }
        
        vector<int> ans(n);
        ans[0] = acc.back();

        int fixed = nums.back() + (n - 2) * nums.front() + acc[n - 2];
        
        for(int i = 1; i < n; i ++){
            /* original
            int leftSum = i *(nums[i] - nums[0]) - acc[i - 1];
            int rightSum = (nums.back() - nums[i]) * (n - 1 - i) + (acc[n - 2] - acc[i])
                - (n - 2 - i) * (nums.back() - nums.front());
            
            ans[i] = leftSum + rightSum;
            */
            
            // after reduction 1:
            //ans[i] = (2*i + 1 - n)*nums[i] + nums.back() + (n-2-2*i)*nums.front() + acc[n-2] - acc[i] - acc[i-1];
    
            // after reduction 2
            ans[i] = fixed + (2*i + 1 - n)*nums[i] - 2 * i * nums.front() - acc[i] - acc[i-1];
        }        
        return ans;
    }
};
