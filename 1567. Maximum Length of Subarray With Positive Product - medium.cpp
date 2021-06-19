//https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        /*
        a subarray with positive product must have even number negatives and no zeros
        p: the product from nums[0] to nums[i]
        case 1: p > 0, the subarray is from nums[0] to nums[i];
        case 2: p > 0, the subarray is from nums[j] to nums[i]. another subarray of zeros prior to nums[j];
        case 3: p < 0, the subarray is from nums[j] to nums[i]. another subarray of negative product prior to nums[j].
        */
        
        //the start and end index of a subarray ending with positive/negative product
        vector<int> pos{-1}, neg;
        //the maximum length of a subarray with positive product
        int maxlen = 0;
        // the number of negatives in current subarray
        int ncount = 0;
        
        for(int i = 0; i < nums.size(); ++ i){
            // when zero shows up, existing subarray ends
            if(nums[i] == 0){
                if(pos.size() == 2)
                    maxlen = max(maxlen, pos[1] - pos[0]);
                if(neg.size() == 2)
                    maxlen = max(maxlen, neg[1] - neg[0]);
                
                pos.resize(1);
                pos[0] = i;                
                neg.clear();
                ncount = 0; // clear ncount
                continue;
            }
            
            if(nums[i] < 0)
                ncount ++;
            
            if(ncount & 1){  // product < 0
                if(neg.size() < 2)
                    neg.push_back(i); // neg[0]: the index of the first negative product of current subarray
                else
                    neg.back() = i; // update neg[1] to the index of the last negative product of current subarray
            }
            else{  // product > 0
                if(pos.size() < 2)
                    pos.push_back(i); // pos[0]: the index of last zero before current subarray or -1
                else
                    pos.back() = i;// update pos[1] to the index of the last positive product of current subarray               
            }            
        }
        
        if(pos.size() == 2)
            maxlen = max(maxlen, pos[1] - pos[0]);
        if(neg.size() == 2)
            maxlen = max(maxlen, neg[1] - neg[0]);
       
        return maxlen;
    }
};
