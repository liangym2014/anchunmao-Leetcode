// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
static int mod = 1000000000 + 7;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int l = 0, r = upper_bound(nums.begin(), nums.end(), target - nums[0]) - nums.begin() - 1;
        
        while(1){
            int mx = target - nums[l];
            while(l <= r && nums[r] > mx)
                -- r;

            if(l > r) break;
            
            int start = l, ele = nums[l];
            
            while(l <= r && nums[l] == ele)
                ++ l;

            int a = modulo(r - l + 1), b = modulo(l - start) - 1;
            ans = (ans + (long long)a * b) % mod;
        }
        
        return ans;
    }
    
    inline int modulo(int order){
        if(order < 31)
            return (1 << order);

        int a = modulo(order >> 1), b = ((long long)a * a) % mod;
        if(order & 1)
            b = (2 * b) % mod;
        return b;
    }
};
