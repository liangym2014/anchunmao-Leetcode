// https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size(), mod = 1000000007;
        if(n == 3)
            return (nums[0] <= nums[1]) && (nums[1] <= nums[2]);
        
        vector<int> sum(n);
        sum[0] = nums[0];
        
        for(int i = 1; i < n; i ++)
            sum[i] = sum[i - 1] + nums[i];
        
        int ans = 0;
        for(int l = 0, limit = sum.back() / 3; (l < n) && (sum[l] <= limit); l ++){// l is the last element in left
            // m is the last element in mid
            // left <= mid: [sum[l] <= (sum[m] - sum[l])] => [sum[m] >= (2 * sum[l])]
            // mid <= right: [(sum[m] - sum[l]) <= (sum[n - 1] - sum[m])] => [sum[m] <= (sum[n - 1] + sum[l])/2]
            // because [(2 * sum[l]) <= (sum[n - 1] + sum[l])/2] => [sum[l] <= sum[n-1] / 3]
            int m_min = 2 * sum[l], m_max = (sum.back() + sum[l])/2;
            int idx2 = upper_bound(sum.begin() + l + 1, sum.begin() + (n - 1), m_max) - sum.begin();
            int idx1 = lower_bound(sum.begin() + l + 1, sum.begin() + (n - 1), m_min) - sum.begin();
            
            ans += idx2 - idx1;
            ans %= mod;
        }
        
        return ans;
    }
};
