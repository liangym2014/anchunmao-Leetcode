// https://leetcode.com/problems/coloring-a-border/
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int target = grid[row][col];
        vector<pair<int,int>> border;
        dfs(grid, border, target, row, col);
        
        for(auto &pos: border){
            grid[pos.first][pos.second] = color;
        }
        
        for(auto &r: grid){
            for(auto &e : r){
                if(e < 0) e = -e;
            }
        }
        
        return grid;
    }
    
    void dfs(vector<vector<int>>& grid, vector<pair<int,int>> &border, int &color, int row, int col){
        bool is_border = false;  //whether grid[row][col] is border
        grid[row][col] *= -1;  // visited elements in connected component are marked as negatives
        vector<pair<int, int>> pos{{row - 1, col}, {row + 1, col}, {row, col - 1}, {row, col + 1}};
        
        for(auto &[r, c]: pos){
            if(r < 0 || r == grid.size() || c < 0 || c == grid[0].size())
                is_border = true;
            else if(grid[r][c] == color)
                dfs(grid, border, color, r, c);
            else if(grid[r][c] > 0)
                is_border = true;
        }
        
        if(is_border)
            border.push_back({row, col});
    }
};
