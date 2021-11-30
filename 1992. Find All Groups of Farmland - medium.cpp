// https://leetcode.com/problems/find-all-groups-of-farmland/
class Solution {
private:
    vector<vector<int>> ans;
    
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++)
                if(land[i][j])
                    counted(land, i, j);
        }
        return ans;
    }
    
    void counted(vector<vector<int>>& land, int lr, int lc){
        int i, j;
        for(i = lr + 1; i < land.size(); i ++)
            if(!land[i][lc])
                break;
        
        for(j = lc + 1; j < land[0].size(); j ++)
            if(!land[lr][j])
                break;
        
        for(int m = lr; m < i; m ++){
            for(int n = lc; n < j; n ++)
                land[m][n] = 0;
        }
        
        ans.push_back({lr, lc, i - 1, j - 1});
    }
};
