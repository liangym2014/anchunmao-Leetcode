// https://leetcode.com/problems/plates-between-candles/
bool cmp1(const pair<int, int> &l, const int &val){
    return l.first < val;
}

bool cmp2(const int &val, const pair<int, int> &r){
    return val < r.first;
}

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<pair<int, int>> arr; //{index of candle, number of plates from 0 to current candle}
        int num_plates = 0;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '|')
                arr.push_back({i, num_plates});
            else
                num_plates ++;
        }
        
        if(arr.empty() || !num_plates){// no candle or no plate
            return vector<int>(queries.size(), 0);
        }
        
        vector<int> ans;
        for(auto& q: queries){
            if(q[0] == q[1]){
                ans.push_back(0);
                continue;
            }
            auto it1 = lower_bound(arr.begin(), arr.end(), q[0], cmp1);
            auto it2 = upper_bound(arr.begin(), arr.end(), q[1], cmp2);
            
            if(it1 == it2){
                ans.push_back(0);
                continue;
            }
            
            ans.push_back((--it2)->second - it1->second);
        }
        return ans;
    }
};
