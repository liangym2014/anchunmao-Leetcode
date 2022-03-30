// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector<int> &l, const vector<int> &r){return l[0] < r[0];});
        int mx_second = properties.back()[1], first = properties.size() - 1, ans = 0, i;
        
        for(i = properties.size() - 2; i >= 0 && (properties[i][0] == properties[i + 1][0]); i --){
            if(properties[i][1] < mx_second)
                properties[i][1] = mx_second;
            else
                mx_second = properties[i][1];
        }
        
        for(; i >= 0; i --){
            if(properties[i][0] != properties[i + 1][0])
                first = i + 1;
    
            ans += (properties[i][1] < properties[first][1]);
            
            if(properties[i][1] < mx_second)
                properties[i][1] = mx_second;
            else
                mx_second = properties[i][1];           
        }
        return ans;
    }
};
