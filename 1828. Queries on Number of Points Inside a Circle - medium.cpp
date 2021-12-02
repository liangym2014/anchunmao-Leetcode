// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size(), m = points.size();
        vector<int> ans(n);
        
        for(int j = 0; j < n; j ++){
            int xj = queries[j][0], yj = queries[j][1], rj = queries[j][2];
            
            for(int i = 0; i < m; i ++){
                int xi = points[i][0], yi = points[i][1];
                
                if(abs(xj - xi) > rj || abs(yj - yi) > rj)
                    continue;
                
                if(sqrt(1.0 * pow(xj - xi,2) + pow(yj - yi, 2)) <= rj)
                    ans[j] ++;
            }
        }
        return ans;
    }
};
