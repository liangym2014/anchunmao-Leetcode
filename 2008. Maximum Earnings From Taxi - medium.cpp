// https://leetcode.com/problems/maximum-earnings-from-taxi/

bool cmp(const vector<int> &l, const vector<int> &r){
    return l[1] < r[1];
}

bool comp(const int &val, const vector<int> &r){
    return val < r[1];
}

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), cmp); // sort in ascending order of end
        
        int l = rides.size();
        vector<long long> earning(l);
        earning[0] = (long long)rides[0][2] + rides[0][1] - rides[0][0];
        
        for(int i = 1; i < l; i ++){
            long long income = (long long)rides[i][2] + rides[i][1] - rides[i][0]; // maximum earning at step i
            
            if(rides[i][0] < rides[i-1][1]){// if current ride overlap with the previous one
                //either keep the previous one's earning, or find the last non-overlapped one's earning + income.
                //depending on which one is larger
                int k = upper_bound(rides.begin(), rides.end(), rides[i][0], comp)- rides.begin();
                earning[i] = max(earning[i-1], (k? earning[k - 1]: 0) + income);
            }
            else{
                earning[i] = earning[i-1] + income;
            }
        }
        return earning.back();
    }
};
