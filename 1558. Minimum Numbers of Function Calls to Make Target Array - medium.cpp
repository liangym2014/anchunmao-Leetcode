// https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int num_calls = 0;
        
        //only continue when nums is not an array of zeros
        while(!all_zeros(nums)){
            // check whether there's odd number in nums
            for(auto &num: nums){
                // minus each odd number by 1
                if(num & 1){
                    num -= 1;
                    num_calls ++;
                }
            }
            
            // check whether nums is an array of zeros. if yes, break
            if(all_zeros(nums))
                break; 
            
            // all elements are even, divide each element by 2
            for(auto &num: nums)
                num >>= 1;

            num_calls ++;            
        }
        return num_calls;
    }
    
    bool all_zeros(vector<int>& nums){
        for(auto &num: nums){
            if(num)  return false;
        }
        
        return true;
    }

};
