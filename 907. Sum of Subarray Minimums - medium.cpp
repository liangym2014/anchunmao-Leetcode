// https://leetcode.com/problems/sum-of-subarray-minimums/
long long M = 1000000007;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mn = arr[0], mn_idx = 0; // the minimum element and its index
        long long res = mn;
        long long gt_acc = 0;  // the accumulation of gt_min part
        // elements on the right of mn and larger than mn, each element is {val, index}
        // elements sorted in ascending order of val
        vector<pair<int,int>> gt_min;   
        
        // each loop computes the sum of min(subarrays ending with arr[i])
        for(int i = 1; i < arr.size(); i ++){
            int cur = arr[i];
            if(cur <= mn){
                mn = cur;
                mn_idx = i;
                gt_min.clear();
                gt_acc = 0;
            }
            
            res += (1 + mn_idx) * mn;
            res %= M;
            
            if(cur > mn){
                int prev_idx;
                while(!gt_min.empty() && gt_min.back().first >= cur){
                    auto [val, idx] = gt_min.back();
                    gt_min.pop_back();
                    prev_idx = gt_min.empty()? mn_idx: gt_min.back().second;
                    gt_acc -= val * (idx - prev_idx);
                }
                
                prev_idx = gt_min.empty()? mn_idx: gt_min.back().second;                
                gt_min.push_back({cur, i});
                gt_acc += (long long)cur * (i - prev_idx);
                res += gt_acc;
                res %= M;
            }
        }
        return res;
    }
};
