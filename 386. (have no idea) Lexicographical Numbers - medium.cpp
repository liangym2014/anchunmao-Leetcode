// https://leetcode.com/problems/lexicographical-numbers/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        ans.reserve(n); // allocate capacity of n for ans
        ans.push_back(1);
        
        while(ans.size() < n){
            // cur: the last element in ans
            // next: next element inserted to ans
            int cur = ans.back(), next = cur * 10;
            if(next <= n){
                ans.push_back(next);
                continue;
            }
            
            next = cur + 1;
            if(next > n)
                next = cur / 10 + 1;
            
            while(next && !(next % 10))
                next /= 10;
            
            ans.push_back(next);
        }
        return ans;
    }
};
