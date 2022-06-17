// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size(), full = 0;
        vector<int> v;
        for(int i = 0; i < n; i ++){
            int remain = capacity[i] - rocks[i];
            if(remain == 0)
                full ++;
            else
                v.push_back(remain);
        }
        
        sort(v.begin(), v.end());
        for(auto &e: v){
            if(additionalRocks >= e){
                full ++;
                additionalRocks -= e;
            }
            else
                break;
        }

        return full;
    }
};
