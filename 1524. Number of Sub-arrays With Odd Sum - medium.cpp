// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum = 0; // sum from arr[0] to arr[i]
        int odd_sum = 0, even_sum = 0; // the number of odd sum and even sum from arr[0] to arr[i]
        int ans = 0, mod = 1000000007;
        
        for(auto &n: arr){
            sum += n;
            
            if(sum & 1){
                odd_sum ++;
                ans += even_sum; // the number of odd sum = odd - the number of previous even sum
            }
            else{
                even_sum ++;
                ans += odd_sum; // the number of odd sum = even - the number of previous odd sum
            }
            ans %= mod;

        }
        return (ans + odd_sum) % mod;
    }
};
