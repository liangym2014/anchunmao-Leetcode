//https://leetcode.com/problems/k-concatenation-maximum-sum/
const int M = 1000000007;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int acc = 0, mx = INT_MIN; // mx: the maximum subarray sum of arr

        for(auto &a: arr){
            acc += a;
            mx = max(mx, acc);

            if(acc < 0)
                acc = 0;
        }
        
        if(k == 1)            
            return max(0, mx) % M;
        
        // mx1: the maximum accumulate sum from left to right
        // mx2: the maximum accumulate sum from right to left
        int mx1 = INT_MIN, mx2 = INT_MIN;
        acc = 0;
        for(int i = 0; i < arr.size(); i ++){
            acc += arr[i];
            if(mx1 < acc)
                mx1 = acc;
        }
        
        acc = 0;
        for(int i = arr.size() - 1; i >= 0 ; i --){
            acc += arr[i];
            if(mx2 < acc)
                mx2 = acc;
        }

        if(acc <= 0){
            if(mx <= 0) return 0;
            if(mx1 <= 0 && mx2 <= 0)  return mx % M;
            if(mx1 <= 0) return max(mx, mx2) % M;
            if(mx2 <= 0) return max(mx, mx1) % M;
            return max((long long)mx,(long long)(mx1 + mx2)) % M;
        }
        
        long long sum = 0; // sum of (k - 2) * arr
        int p = INT_MAX / acc, d = (p * acc) % M;
        k -= 2;

        while(k >= p){
            sum += (long long)d;
            k -= p;
            if(sum > INT_MAX)
                sum %= M;
        }
        sum += (long long)k * acc;
        sum %= M;
        sum += (long long)(mx1 + mx2);

        return max(sum, (long long)mx) % M;
    }
};
