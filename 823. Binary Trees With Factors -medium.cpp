/*
https://leetcode.com/problems/binary-trees-with-factors/
*/
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0, mod = 1000000007;
        
        vector<long> dp(arr.size(), 1); //each element constructs a binary tree with one node

        for(int i = 0; i < arr.size(); ++ i){
            for(int l = 0, r = i - 1; l <= r;){
                long p = (long)arr[l] * arr[r];
                
                if(p > arr[i]){
                    -- r;
                    continue;
                }
                else if(p < arr[i]){
                    ++ l;
                    continue;
                }
                else if(l == r)
                    dp[i] += (long)dp[l] * dp[r];
                else
                    dp[i] += 2 * (long)dp[l] * dp[r];

                ++ l;
                -- r;                
                dp[i] %= mod;
            }
            
            ans += dp[i];
            ans %= mod;
        }
        
        return ans;
    }
};
