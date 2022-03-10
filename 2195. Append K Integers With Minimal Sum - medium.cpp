// https://leetcode.com/problems/append-k-integers-with-minimal-sum/
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<int> s(nums.begin(), nums.end());

        if(*s.begin() > k)
            return (long long)k * (1 + k) / 2;
        
        int n = s.size() + k;
        
        if(*s.rbegin() <= n)
            return compute_sum(1, n, n, s.begin(), s.end());
        
        int prev = 0;        
        long long sum = 0;
        while(k){
            int t = prev + k;
            auto it = s.upper_bound(t);
            int d = distance(s.begin(), it);
            
            if(d == k){
                s.erase(s.begin(), it);                
                prev = t;
                continue;
            }
            
            if(d){
                sum += compute_sum(prev + 1, t, k, s.begin(), it);
                s.erase(s.begin(), it);
                prev = t;
            }
            else
                sum += (long long)k * (prev + 1 + t) / 2;

            k = d;
        }
        return sum;
    }
    
    inline long long compute_sum(int start, int end, int n, set<int>::iterator l, set<int>::iterator r){
        return (long long)n * (start + end) / 2 - accumulate(l, r, (long long)0);
    }
};
