// https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int acc = 0, max_sum = -1e9;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i ++){ // for case i: 1 ~ n
            acc += nums[i];
            int score = i - 2 * acc;
            if(score < max_sum)
                continue;
            
            if(score == max_sum){
                ans.push_back(i+1);
                continue;
            }

            max_sum = score;
            ans = {i + 1};
        }
        if(1 + max_sum < 0)
            return {0};
        
        if(1 + max_sum == 0)
            ans.push_back(0);
        
        return ans;
    }
};
