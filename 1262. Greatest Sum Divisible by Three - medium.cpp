// https://leetcode.com/problems/greatest-sum-divisible-by-three/
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // r1: keep the smallest two elements in nums which % 3 == 1
        // r2: keep the smallest two elements in nums which % 3 == 2
        vector<int> r1, r2;
        int ans = 0, n1 = 0, n2 = 0;// ans: the sum of all elements in nums
        
        // a sum that could be divisible by 3 consists of either:
        //1. element % 3 == 0  ==> ans should include all these elements
        //2. a triple, each % 3 == 1
        //3. a triple, each % 3 == 2
        //4. a pair, one % 3 == 1, the other % 3 == 2        
        for(auto &num: nums){
            ans += num;            
            int remainder = num % 3;

            if(remainder == 1){
                update_list(r1, num);
                n1 ++;
            }
            else if(remainder == 2){
                update_list(r2, num);
                n2 ++;
            }
        }

        
        int res1 = n1 % 3, res2 = n2 % 3;
 
        if(res1 == res2) // elements that % 3 == 1 and that % 3 == 2 form pairs, no one left behind
            return ans;
        
        if(n1 < n2){  //make sure n1 > n2
            swap(r1, r2);
            swap(res1, res2);
        }
        
        if(((!res1) && (res2 == 1)) || ((res1 == 1) && (res2 == 2)) || ((res1 == 2) && (!res2))){
            // either pop the 1st element of r2, or the first 2 elements of r1, whichever is smaller
            int one_r2 = (r2.size() < 1)? INT_MAX : r2[0];
            int two_r1 = (r1.size() < 2)? INT_MAX : (r1[0] + r1[1]);

            ans -= min(one_r2, two_r1);
        }
        else{ // (res1 == 0 && res2 == 2) || (res1 == 1 && res2 == 0) || (res1 == 2 && res2 == 1)
            // either pop the first 2 elements of r2, or the 1st element of r1, whichever is smaller
            int two_r2 = (r2.size() < 2)? INT_MAX : (r2[0] + r2[1]);
            int one_r1 = (r1.size() < 1)? INT_MAX : r1[0];

            ans -= min(two_r2, one_r1); 
        }

        return ans;
    }
    
    inline void update_list(vector<int> &arr, int &num){
        if(arr.size() < 2){
            arr.push_back(num);
            sort(arr.begin(), arr.end());
        }
        else if(num >= arr.back())
            return;
        else if(num < arr[0]){
            arr[1] = arr[0];
            arr[0] = num;
        }
        else if(num < arr[1])
            arr.back() = num;
    }
};
