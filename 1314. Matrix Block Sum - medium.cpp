// https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();

        if(k >= max(m, n)){
            int sum = 0;
            for(int i = 0; i < m; i ++){
                for(int j = 0; j < n; j ++){
                    sum += mat[i][j];
                }
            }
            return vector<vector<int>>(m, vector<int>(n, sum));
        }
        
        for(int i = 0; i < m; i ++){
            for(int j = 1; j < n; j ++){
                mat[i][j] += mat[i][j - 1];
            }
        }
        
        vector<vector<int>> ans(m, vector<int>(n));
        
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                for(int r = max(i - k, 0), c = min(n - 1, j + k), rl = min(i + k, m - 1); r <= rl; r ++){
                    ans[i][j] += mat[r][c] - ((j - k) >= 1? mat[r][j - k - 1]: 0);
                }
            }
        }
        return ans;
    }
};
