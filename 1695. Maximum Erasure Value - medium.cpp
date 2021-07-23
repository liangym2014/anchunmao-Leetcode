// https://leetcode.com/problems/maximum-erasure-value/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool> existed(1 + *max_element(nums.begin(), nums.end()));
        existed[nums[0]] = true;
        
        int score = nums[0], maxscore = nums[0], start = 0;
        
        for(int end = 1; end < nums.size(); end ++){
            if(existed[nums[end]]){
                maxscore = max(maxscore, score);
                
                do{
                    score -= nums[start];
                    existed[nums[start]] = false;

                }while(nums[start ++] != nums[end]);
            }
            
            score += nums[end];
            existed[nums[end]] = true;           
        }
        maxscore = max(maxscore, score);
        return maxscore;
    }
};
