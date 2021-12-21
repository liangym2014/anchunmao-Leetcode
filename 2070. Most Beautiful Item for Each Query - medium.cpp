// https://leetcode.com/problems/most-beautiful-item-for-each-query/
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> m;
        for(auto &item: items)
            m[item[0]] = max(m[item[0]], item[1]);
        
        int max_beauty = 0;
        for(auto &e:m){
            if(max_beauty < e.second)
                max_beauty = e.second;
            else
                e.second = max_beauty;
        }
        
        vector<int> ans(queries.size(), 0);
        unordered_map<int, int> existed_ans;
        for(int i = 0; i < queries.size(); ++ i){
            if(existed_ans.find(queries[i]) != existed_ans.end()){
                ans[i] = existed_ans[queries[i]];
                continue;
            }
            auto it = m.upper_bound(queries[i]);
            if(it != m.begin())
                ans[i] = (-- it) -> second;
            
            existed_ans[queries[i]] = ans[i];
        }
        return ans;
    }
};
