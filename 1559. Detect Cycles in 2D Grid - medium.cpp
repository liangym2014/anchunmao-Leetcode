// https://leetcode.com/problems/detect-cycles-in-2d-grid/
class Solution {
private:
    char val;
    int start, step_idx = 0;
    vector<vector<int>> steps;
    
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 1 || n == 1)
            return false;
        
        steps = vector<vector<int>>(m, vector<int>(n));
        
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(steps[i][j])  // visited
                    continue;

                val = grid[i][j];
                start = step_idx + 5;
                if(dfs(grid, start, i, j))
                    return true;
            }
        }
        return false;
        
    }
    
    bool dfs(vector<vector<char>>& grid, int step, int row, int col){
        steps[row][col] = step;
        int last_move = step - 1;
        
        for(int i = row - 1; i <= (row + 1); i += 2){
            if(i < 0 || i >= grid.size() || steps[i][col] == last_move)
                continue;

            if(steps[i][col] >= start)  // in the path, but not the last move
                return true;
            else if(grid[i][col] == val && dfs(grid, step + 1, i, col))
                return true;
        }
       
        for(int i = col - 1; i <= (col + 1); i += 2){
            if(i < 0 || i >= grid[0].size() || steps[row][i] == last_move)
                continue;

            if(steps[row][i] >= start)  // in the path, but not the last move
                return true;
            else if(grid[row][i] == val && dfs(grid, step + 1, row, i))
                return true;
        }

        step_idx = max(step_idx, step);
        grid[row][col] = ' ';
        return false;    
    }
};
