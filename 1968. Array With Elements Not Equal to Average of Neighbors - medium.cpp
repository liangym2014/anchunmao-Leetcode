// https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
       
        // construct a zigzag-like list, so that either neighbors are both greater than the current element,
        // or they're both less than the current element.
        for(int i = 2; i <nums.size(); i += 2){
            swap(nums[i - 1], nums[i]);
        }
        return nums;
    }
};
