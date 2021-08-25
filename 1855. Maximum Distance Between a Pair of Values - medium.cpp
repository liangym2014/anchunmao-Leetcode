// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.back() > nums2.front())
            return 0;
        
        reverse(nums2.begin(), nums2.end());
      
        int l2 = nums2.size() - 1, d = 0, i2;
      
        for(int i = 0; i < nums1.size(); i ++){
            if(!i || nums1[i] != nums1[i - 1])
                i2 = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            
            int j = l2 - i2;
            
            if(i > j)
                continue;
            d = max(d, j - i);
        }
        
        return d;
    }    

};
