// https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int idx = 0;  // the index of 1st element available to use
        
        // the next value to be made by coins
        int x = 1;
        
        // element_found: a boolean indicating whether a proper element is found to make value x        
        bool element_found = false;

        while(1){
            if(idx < coins.size() && coins[idx] <= x){
                x += coins[idx ++]; // this coin is used, removed from available list
                element_found = true;
            }
            
            if(!element_found) //breakpoint
                return x;

            element_found = false;
        }
        
        return -1;

    }
};
