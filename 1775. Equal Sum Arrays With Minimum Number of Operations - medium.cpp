// https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0, sum2 = 0;
        vector<int> a1(7), a2(7);
        
        for(auto &n: nums1)
            a1[n] ++;
        
        for(auto &n: nums2)
            a2[n] ++;
        
        for(int i = 1; i <= 6; i ++){
            sum1 += i * a1[i];
            sum2 += i * a2[i];
        }

        int ans = 0, n1 = nums1.size(), n2 = nums2.size();
  
        if(sum1 == sum2)
            return ans;
      
        //make sum1 > sum2
        if(sum2 > sum1){
            swap(sum1, sum2);
            swap(a1, a2);
            swap(n1, n2);
        }
        
        if(sum1 > sum2){
            if(n1 > (n2 * 6))
                return -1;
            
            int diff = sum1 - sum2, i = 1;
            while(diff){
                int var = 6 - i;
                if(diff > (a2[i] * var)){
                    ans += a2[i];
                    diff -= a2[i] * var;
                }
                else{
                    ans += ceil(1.0 * diff/var);
                    break;
                }
                
                int i2 = 7 - i;
                if(diff > (a1[i2] * var)){
                    ans += a1[i2];
                    diff -= a1[i2] * var;
                }
                else{
                    ans += ceil(1.0 * diff/var);
                    break;
                }
                i ++;
            }
            
        }

        return ans;
    }
};
