// https://leetcode.com/problems/finding-the-users-active-minutes/
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, set<int>> uam; //key: user id, value: time
        for(auto &log: logs){
            uam[log[0]].insert(log[1]);
        }
        
        vector<int> ans(k);
        for(auto &user: uam){
            ans[user.second.size() - 1] ++;
        }
        return ans;
    }
};
