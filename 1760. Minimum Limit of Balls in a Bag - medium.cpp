// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        long long sum = accumulate(nums.begin(), nums.end(), (long long)0);
        int final_bags = (int)nums.size() + maxOperations, 
            l = sum / final_bags, 
            r = *max_element(nums.begin(), nums.end());

        while(l < r){
            int mid = l + (r - l) / 2, bags = 0;
            
            if(!mid)
                return 1;

            for(auto &num:nums)
                bags += (num <= mid)? 1: ceil(1.0 * num / mid);

            if(bags > final_bags)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
