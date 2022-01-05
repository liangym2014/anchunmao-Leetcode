// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> arrival_time(dist.size());
        for(int i = 0; i < dist.size(); i ++)
            arrival_time[i] = 1.0 * dist[i] / speed[i];

        sort(arrival_time.begin(), arrival_time.end());
        int i = 0;
        while(i < dist.size() && i < arrival_time[i]){
            i ++;
        }
        return i;
    }
};
