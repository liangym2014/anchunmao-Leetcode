// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = *max_element(quantities.begin(), quantities.end()), res;
        while(l <= r){
            int mid = l + (r - l) / 2, acc = 0;
            
            for(auto &q: quantities){
                acc += ceil(1.0 * q / mid);
            }

            if(acc > n)
                l = mid + 1; 
            else{
                res = mid;
                r = mid - 1;
            }
        }
        return res;
    }
};
