// https://leetcode.com/problems/longest-well-performing-interval/
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0, acc = 0;
        // each element is {minimum, index}, v is reversed sorted on minimum
        vector<pair<int, int>> v(1, {0, -1}); 
        
        for(int i = 0; i < hours.size(); i ++){
            // acc is the sum of tiring day(corresponding to 1) and 
            // non-tiring day(corresponding to -1) in hours[0:i].
            // a well-performing interval must have a positive sum ==> acc > minimum.
            acc += (hours[i] > 8)? 1: (-1);
            
            if(acc > 0){
                ans = i + 1;
                continue;
            }
            
            if(acc < v.back().first){
                v.push_back({acc, i});
                continue;
            }

            // search for the first element in v the minimum of which is smaller than acc
            int j = upper_bound(v.begin(), v.end(), acc, 
                                [](const int &val, const pair<int, int> r){return val > r.first;}) - v.begin();
            if(j < v.size())
                ans = max(ans, i - v[j].second);

        }
        return ans;
    }
};
