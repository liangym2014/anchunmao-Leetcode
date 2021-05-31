// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/submissions/

#include <limits.h>
#include <algorithm>
#include <vector>

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        if(arr.front() * n >= target){
            int left = target / n, right = left + 1;
            
            if((right * n - target) < (target - n * left))
                return right;
            
            return left;
        }
        
        if(arr.back() * n <= target)
            return arr.back();
        
        vector<int> sum{arr.front()};
        for(int i = 1; i < n; ++ i)
            sum.push_back(sum[i - 1] + arr[i]);
        
        int left = arr.front(), right = arr.back(), ans = 0, diff = INT_MAX;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            int idx = lower_bound(arr.begin(), arr.end(), mid) - arr.begin(); // the position of 1st element >= mid
            int total = (idx? sum[idx - 1]: 0) + (n - idx) * mid; // the sum after changing values that are larger than mid to mid
            
            if(total == target)
                return mid;
            else if(total < target){
                left = mid + 1;
                int _diff = target - total;
                
                if(_diff < diff){
                    diff = _diff;
                    ans = mid;
                }
                else if(_diff == diff)
                    ans = min(ans, mid);
            }
            else{
                right = mid - 1;
                int _diff = total - target;
                
                if(_diff < diff){
                    diff = _diff;
                    ans = mid;
                }
                else if(_diff == diff)
                    ans = min(ans, mid);                
            }
        }
        return ans;
    }
};
