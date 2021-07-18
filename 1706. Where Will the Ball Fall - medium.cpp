// https://leetcode.com/problems/where-will-the-ball-fall/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);
        for(int i = 0; i < n; i ++)
            ans[i] = dfs(grid, 0, i);
        return ans;
    }
    
    int dfs(vector<vector<int>>& grid, int row, int col){
        if(row == grid.size())
            return col;
        
        if(grid[row][col] > 0){//to the right
            if(col + 1 == grid[0].size())  // hit right wall
                return -1;
            if(grid[row][col + 1] < 0) // V shape
                return -1;
            return dfs(grid, row + 1, col + 1);
        }
        
        //to the left
        if(col < 1) // hit left wall
            return -1;
        if(grid[row][col - 1] > 0)  // V shape
            return -1;
        return dfs(grid, row + 1, col - 1);
    }
};
