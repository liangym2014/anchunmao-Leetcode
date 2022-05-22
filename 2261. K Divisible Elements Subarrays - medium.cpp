// https://leetcode.com/problems/k-divisible-elements-subarrays/
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int ans = 0, acc = 0;
        unordered_map<int, int> m({{0, -1}}); // key: number of elements divisible by p in nums[0:i], value: i
        unordered_set<string> ds; // distinct subarrays
        
        for(int i = 0; i < nums.size(); i ++){
            if((nums[i] % p) == 0)
                m[++ acc] = i;

            int l = (acc < k)? (-1): m[acc - k];
            ans += cal_subarray(ds, nums, i, l);
        }
        return ans;
    }
    
    int cal_subarray(unordered_set<string> &ds, vector<int> &nums, int r, int l){
        int res = 0;
        string s;
        for(int i = r; i > l; i --){
            s += to_string(nums[i]) + " ";
            
            if(!ds.count(s)){
                ds.insert(s);
                res ++;
            }
        }
        return res;
    }
};
