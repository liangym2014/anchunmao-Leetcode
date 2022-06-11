// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < x)
            return -1;
        
        if(sum == x)
            return nums.size();

        int acc = 0, l = 0, target = sum - x;  // find the longest subarray with sum of target
        int len = 0;
        for(int i = 0; i < nums.size(); i ++){
            acc += nums[i];
            while(acc > target)
                acc -= nums[l ++];

            if(acc == target)
                len = max(len, i - l + 1);
        }
        return (len == 0)? (-1): (nums.size() - len);
    }
