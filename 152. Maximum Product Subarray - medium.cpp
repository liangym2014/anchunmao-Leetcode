// https://leetcode.com/problems/maximum-product-subarray/
class Solution {
private:
    int ans = INT_MIN; // the maximum product
    int p = INT_MAX; // the product for a subarray, initialized with an invalid value
    int positive = 0; // a flag for whether positive products exist in a subarray, non-zero means true
    // for a subarray nums[i:j] without 0 and with a negative product, record store two values:
    // 1. the first negative product
    // 2. the last positive product before a negative element
    int first_neg_product = 1, last_pos_product = -1;  //initialized with an invalid value
    
public:
    int maxProduct(vector<int>& nums) {
        for(auto &num: nums){
            if(p == INT_MAX){ // first element in a valid subarray should be a non-zeo value
                if(num){
                    p = num;
                    if(p < 0)
                        first_neg_product = p;
                }
                else
                    ans = max(ans, 0);
                continue;
            }
            
            if(num > 0){
                ++ positive;
                p *= num;
            }
            else if(num < 0){
                if(p > 0){
                    if(first_neg_product > 0)
                        first_neg_product = p * num;
                    ++ positive;
                    last_pos_product = p;
                }
                    
                p *= num;
            }
            else{ // num == 0
                update_product();
                ans = max(ans, 0);                
                p = INT_MAX;
                first_neg_product = 1;
                last_pos_product = -1;
                positive = 0;
            }
        }

        if(p != INT_MAX)
            update_product();
        
        return ans;
    }
    
    inline void update_product(){
        if(p >= 0 || !positive)
            ans = max(ans, p);
        else{
            int t = max(p/first_neg_product, last_pos_product);
            ans = max(ans, t);
        }        
    }
    
};
