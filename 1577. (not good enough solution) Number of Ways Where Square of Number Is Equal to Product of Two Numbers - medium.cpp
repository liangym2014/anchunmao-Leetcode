// https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long, int> m1, m2;
        for(int i = 0; i < nums1.size(); i ++){
            m1[(long long)nums1[i] * nums1[i]] ++;
            for(int j = i + 1; j < nums1.size(); j ++){
                m2[(long long)nums1[i] * nums1[j]] ++;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < nums2.size(); i ++){
            long long key = (long long)nums2[i] * nums2[i];
            if(m2.find(key) != m2.end())
                ans += m2[key];
            for(int j = i + 1; j < nums2.size(); j ++){
                key = (long long)nums2[i] * nums2[j];
                
                if(m1.find(key) != m1.end())
                    ans += m1[key];
            }
        }
        return ans;
    }
};
