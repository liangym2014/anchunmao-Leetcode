// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        
        for(int i = 0; i < grid.size(); ++ i){
            for(int j = 0; j < grid[0].size(); ++ j){
                if(grid[i][j] == 1)
                    max_area = max(max_area, dfs(grid, i, j));
            }
        }
        return max_area;
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c){
        int area = 1;
        grid[r][c] = -1;  // visited cell marked as -1
        
        for(int i = r - 1; i < (r + 2); i += 2){
            if(i >= 0 && i < grid.size() && grid[i][c] == 1)
                area += dfs(grid, i, c);
        }

        for(int i = c - 1; i < (c + 2); i += 2){
            if(i >= 0 && i < grid[0].size() && grid[r][i] == 1)
                area += dfs(grid, r, i);
        }
        return area;
    }
};
