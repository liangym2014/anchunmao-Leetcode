// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int window = accumulate(nums.begin(), nums.end(), 0);
        if(nums.size() - window < 2) // elements are all "1" or only have one "0"
            return 0;
        
        int acc = accumulate(nums.begin(), nums.begin() + window, 0), num_ones = acc, l = 0;
        for(int i = window; i < nums.size(); i ++){
            acc += nums[i] - nums[l ++];
            if(acc > num_ones)
                num_ones = acc;
        }
        
        for(int i = 0, lim = window - 1; i < lim; i ++){
            acc += nums[i] - nums[l ++];
            if(acc > num_ones)
                num_ones = acc;            
        }
        
        return window - num_ones;
    }
};
