// https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    //solution 3:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> m(k); // index: residual of sum of nums[0: i] % k, value: count of each residual
        m[0] = 1;  // corresponding to empty substring nums[-1]
        int sum = 0, ans = 0;
        
        for(int i = 0; i < nums.size(); i ++){
            sum += nums[i];
            int residual = sum % k;
            m[residual + (residual < 0? k: 0)] ++;
        }
        
        // for subarray nums[i+1:j] = nums[0:j] - nums[0:i]
        // if nums[i+1:j] % k == 0, then (nums[0:j] - nums[0:i]) % k = nums[0:j] % k - nums[0:i]) % k == 0
        // therefore, nums[0:j] % k == nums[0:i]) % k, that means they must be in the same bucket of m
        for(auto &e: m){
            ans += e * (e - 1) / 2;
        }
        return ans;
    }
};
