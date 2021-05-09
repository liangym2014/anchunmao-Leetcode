/*
https://leetcode.com/problems/jump-game-ii/
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        if(n == 1)   return 0;
        
        vector<int> steps(n, 1001);
        steps[0] = 0;
        
        for(int i = 0; i < n; ++ i){
            if(!nums[i])  continue;
            
            int updated_step = steps[i] + 1;
            
            for(int step = 1, limit = min(nums[i] + 1, n - i); step < limit; ++ step){
                if(steps[i + step] > updated_step){
                    steps[i + step] = updated_step;
                }
            }
        }
        
        return steps.back();
    }
};
