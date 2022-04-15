// https://leetcode.com/problems/find-players-with-zero-or-one-losses/
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> m;
        for(auto &match: matches){
            m[match[0]] += 0;
            m[match[1]] ++;
        }
        
        vector<int> win, lost1;
        for(auto& [k, v]: m){
            if(v > 1)
                continue;
            
            if(v == 0)
                win.push_back(k);
            else
                lost1.push_back(k);
        }
        
        sort(win.begin(), win.end());
        sort(lost1.begin(), lost1.end());
        return {win, lost1};
    }
};
