// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0], y = target[1], z = target[2];
        int a = 0, b = 0, c = 0; // store the maximum element <= (x,y,z)
        
        for(auto &t: triplets){
            if(t[0] > x || t[1] > y || t[2] > z)
                continue;
            a = max(a, t[0]);
            b = max(b, t[1]);
            c = max(c, t[2]);
            
            if(a == x && b == y && c == z)
                return true;
        }
        
        return false;
        
    }
};
