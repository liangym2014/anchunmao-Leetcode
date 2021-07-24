//https://leetcode.com/problems/tuple-with-same-product/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> prod; // key: product of the two elements in tuple (nums[i], nums[j]), value: count
        
        for(int i = 0; i < nums.size(); i ++){
            for(int j = i + 1; j < nums.size(); j ++){
                prod[nums[i] * nums[j]] ++;
            }
        }
        
        int ans = 0;
        
        for(auto &p: prod){
            if(p.second == 1)
                continue;
            //if the number of two-element tuples with the same proudct > 1, choose two two-element tuples to construct
            // a four-element tuple (a,b,c,d), the number of such combinations =(p.second - 1)* p.second / 2;
            //for each four-element tuple, the number of variations between a,b,c,d = 2 * 2 * 2 = 8
            ans += (p.second - 1)* p.second * 4;
        }
        return ans;
    }
};
