// https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int startx = startPos[0], starty = startPos[1];
        int endx = homePos[0], endy = homePos[1];
       
        int row_cost = accumulate(rowCosts.begin() + min(startx, endx),
                             rowCosts.begin() + max(startx, endx) + 1, 0) - rowCosts[startx];

        int col_cost = accumulate(colCosts.begin() + min(starty, endy),
                             colCosts.begin() + max(starty, endy) + 1, 0) - colCosts[starty];
        return row_cost + col_cost;
    }
};
