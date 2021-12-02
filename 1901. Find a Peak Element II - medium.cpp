// https://leetcode.com/problems/find-a-peak-element-ii/

// solution 1: O(m * n)
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> pos{0, 0};
        
        while(1){
            vector<int> max_pos = max_position(mat, pos); // find the coordinates of the local peak among pos and its neighbors
            if(max_pos[0] == pos[0] && max_pos[1] == pos[1])
                break;
            
            pos = max_pos;   // update pos with the coordinates of local peak
        }
        return pos;
    }
    
    vector<int> max_position(vector<vector<int>> &mat, vector<int> &pos){
        int i = pos[0], j = pos[1];
        vector<int> max_element = pos;
        
        if(i && mat[i-1][j] > mat[max_element[0]][max_element[1]])
            max_element = {i - 1, j};

        if(j && mat[i][j-1] > mat[max_element[0]][max_element[1]])
            max_element = {i, j - 1};
        
        if(i + 1 < mat.size() && mat[i+1][j] > mat[max_element[0]][max_element[1]])
            max_element = {i + 1, j};

        if(j + 1 < mat[0].size() && mat[i][j+1] > mat[max_element[0]][max_element[1]])
            max_element = {i, j + 1};
        
        return max_element;

    }
};


// solution 2: binary search O(mlogn)
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = 0, r = mat[0].size() - 1;
        
        while(l < r){
            if(r - l == 1){
                pair<int, int> lcol_max = max_in_col(mat, l),
                rcol_max = max_in_col(mat, r);
                
                if(mat[lcol_max.second][l] > mat[lcol_max.second][r])
                    return {lcol_max.second, l};
                else
                    return {rcol_max.second, r};
            }
            
            int mid = l + (r - l) / 2;
            pair<int, int> col_max = max_in_col(mat, mid),  // the peak at column mid
            leftcol_max = max_in_col(mat, mid - 1),  // the peak at column (mid - 1)
            rightcol_max = max_in_col(mat, mid + 1);  // the peak at column (mid + 1)
            
            if(col_max.first > leftcol_max.first && col_max.first > rightcol_max.first)
                return {col_max.second, mid};
            else if(col_max.first <= leftcol_max.first)
                r = mid;
            else  // col_max.first <= rightcol_max.first
                l = mid;
            
        }
        return {-1, -1};
    }
    
    pair<int, int> max_in_col(vector<vector<int>> &mat, int col){
        pair<int, int> mx{-1, -1}; // first: max element, second: the corresponding row
        
        if(col < 0 || col >= mat[0].size())
            return mx;
        
        for(int i = 0; i < mat.size(); i ++){
            if(mx.first < mat[i][col])
                mx = {mat[i][col], i};
        }
        return mx;
    }
    
};
