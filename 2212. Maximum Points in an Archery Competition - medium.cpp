// https://leetcode.com/problems/maximum-points-in-an-archery-competition/
class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<vector<int>> v{{0, numArrows, 0}}; // {points, remain arrows,pos}
        
        // idx: the index of element in v with maximum points
        // mx_points: the maximum points bob can get
        int idx = 0, mx_points = 0;
        
        for(int i = 11; i; i --){
            int possible_maximum = (i + 1) * i / 2; // the maximum points bob could get from section[1] ~ section[i]
            int l = v.size(), used_arrows = aliceArrows[i] + 1, mask = (1 << (11 - i));
            
            for(int j = 0; j < l; j ++){
                int points = v[j][0], arrows = v[j][1], pos = v[j][2];
                // at each section i, we have two options: 
                // 1. use (aliceArrows[i] + 1) arrows => bob get section[i] points
                // 2. not use any arrows => bob get no points
                
                // if the maximum points from section[1] ~ section[i], plus points already got
                // wouldn't exceed the maximum points we get so far, no need to further address this solution
                if(points + possible_maximum <= mx_points)
                    continue;
                
                if(arrows >= used_arrows){
                    int p = i + points, remain_arrows = arrows - used_arrows;
                    
                    if(p > mx_points){
                        mx_points = p;
                        idx = v.size();
                    }
                    v.push_back({p, remain_arrows, pos | mask});                    
                }
            }
        }
        
        vector<int> bob(aliceArrows.size());
        int pos = v[idx][2], remain = numArrows;
        for(int i = 11; i; i --){
            if((pos >> (11 - i)) & 1){
                bob[i] = aliceArrows[i] + 1;
                remain -= bob[i];
            }
        }

        bob.back() += remain;
        return bob;
    }
};
