// https://leetcode.com/problems/avoid-flood-in-the-city/
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> full_lakes;
        int i = 0;
        while(i < rains.size() && rains[i]){ // fill the lakes
            if(full_lakes.count(rains[i])) // if a full lake is filled, flood appears
                return {};
            full_lakes[rains[i]] = i;
            rains[i ++] = -1;
        }        
        
        set<int> drain_day;  // indices of days you can empty a lake
        while(i < rains.size()){
            while(i < rains.size() && !rains[i])
                drain_day.insert(i ++);
            
            while(i < rains.size() && rains[i]){ // lakes that're about to be filled
                if(full_lakes.count(rains[i])){
                    int idx = full_lakes[rains[i]];  // last time when rains[i]th lake is filled
                    auto it = drain_day.upper_bound(idx);  // find the 1st day which is > idx we could drain this lake
                    // if we can't find such a day, flood appears
                    if(it == drain_day.end())
                        return {};
                    
                    rains[*it] = rains[i];
                    drain_day.erase(it);
                }
                full_lakes[rains[i]] = i; // update the filled day of rains[i]th lake to i
                rains[i ++] = -1;
            }
        }
        
        // if still have days to empty lakes, always drain lake 1
        for(auto it = drain_day.begin(); it != drain_day.end(); ++ it) 
            rains[*it] = 1;
        
        return rains;
    }
};
