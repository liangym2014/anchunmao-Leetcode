// https://leetcode.com/problems/minimum-area-rectangle/
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> xbase;
        for(auto &e: points)
            xbase[e[0]].push_back(e[1]);  // put points with the same x into one bucket
        
        unordered_map<int, unordered_set<int>> candidates;
        for(auto &e: xbase){
            if(e.second.size() > 1)
                candidates[e.first] = unordered_set<int>(e.second.begin(),
                                   e.second.end()); // keep buckets with 2 or more points as candidates
        }
        
        if(candidates.size() < 2)
            return 0;
        
        int area = INT_MAX;
        
        for(auto i = candidates.begin(); i != candidates.end(); ++ i){
            int x1 = i->first;
            vector<int> y1(i->second.begin(), i->second.end());
            
            for(int i1 = 0; i1 < y1.size(); i1 ++){
                int y11 = y1[i1];
                
                for(int i2 = i1 + 1; i2 < y1.size(); i2 ++){
                    int y12 = y1[i2], delta_y = y11 - y12;
                    
                    auto j = i;
                    for(++ j; j != candidates.end(); ++ j){
                        if(j->second.count(y11) && j->second.count(y12)){
                            area = min(area, abs(delta_y * (j->first - x1)));
                        }
                    }                    
                }
            }

        }
        return area == INT_MAX? 0: area;
   
    }
};
