// https://leetcode.com/problems/minimum-sideway-jumps/
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size(), mxdist = 1e9;
        int d1 = 0, d2 = 0, d3 = 0;  // minimum distance from lane 1/2/3 at position (i + 1) to the end

        for(int i = n - 2; i >= 0; i --){
            int x1 = mxdist, x2 = mxdist, x3 = mxdist; // minimum distance from lane 1/2/3 at position i to the end

            switch(obstacles[i]){  // obstacle appears on which lane at position i
                case 0:
                    x1 = min({d1, 1 + d2, 1 + d3});// horizontal connection has weight 0, vertical connection has weight 1
                    x2 = min({1 + d1, d2, 1 + d3});
                    x3 = min({1 + d1, 1 + d2, d3});
                    break;

                case 1: // if obstacle appears on lane 1, any route from lane 1 to the end is mxdist
                    x2 = min(d2, 1 + d3);
                    x3 = min(d3, 1 + d2);
                    break;
                
                case 2:
                    x1 = min(d1, 1 + d3);
                    x3 = min(d3, 1 + d1);
                    break;

                default:
                    x1 = min(d1, 1 + d2);
                    x2 = min(d2, 1 + d1);
            }

            d1 = x1;
            d2 = x2;
            d3 = x3;

        }
        return d2;
    }
};
