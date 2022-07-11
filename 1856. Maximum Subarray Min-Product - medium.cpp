//https://leetcode.com/problems/maximum-subarray-min-product/
auto cmp = [](const pair<int, int>& l, const int& val){return l.first < val;};

class Solution {
private:
    vector<long long> acc;
    vector<pair<int, int>> v;  // {value, index}    
    long long mx = 0;
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        
        acc.resize(n);
        acc[0] = nums[0];

        for(int i = 1; i < n; i ++){
            acc[i] = acc[i - 1] + nums[i];
        }

        v.push_back({nums[0], 0});  // let v become a non-descending array
    
        for(int i = 1; i < n; i ++){
            while(!v.empty()){
                long long t = v.back().first;
                // only process when the last element in v > nums[i]
                if(t <= nums[i])
                    break;
                v.pop_back();
                process(acc[i - 1], t);                
            }

            v.push_back({nums[i], i});
        }
        
        while(!v.empty()){
            long long t = v.back().first;
            v.pop_back();            
            process(acc.back(), t);
        }
        return mx % 1000000007;
    }
    
    void process(long long& total, long long& t){
        // find the index of the 1st element < t        
        auto it = lower_bound(v.begin(), v.end(), t, cmp);
        long long prev = (it != v.begin())? acc[(--it)->second]: 0;
        
        // compute min-product by t * (total - prev)
        long long min_prod = t * (total - prev);
        
        // compare with mx        
        mx = max(mx, min_prod);

        while(!v.empty() && v.back().first == t)  // if the last element in v is the same as its predecessor
            v.pop_back();   // no need to process        
    }
};
