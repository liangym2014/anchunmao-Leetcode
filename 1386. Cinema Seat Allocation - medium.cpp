// https://leetcode.com/problems/cinema-seat-allocation/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end(), [](const vector<int>& left, const vector<int>& right){
            return left[0] < right[0]; });
        
        int ans = 0;
        int cur_row = 0;  // store the reservation of seats in current row
        
        ans += 2 * (reservedSeats[0][0] - 1);
        cur_row |= 1 << (reservedSeats[0][1] - 1);

        for(int i = 1; i < reservedSeats.size(); ++ i){
            // still at the same row, continue collecting other reserved seats
            if(reservedSeats[i][0] == reservedSeats[i - 1][0]){
                cur_row |= 1 << (reservedSeats[i][1] - 1);
                continue;
            }
            
            // handle current row 
            if(!(cur_row & 510)) // if seat 2 - 9 are vaccant
                ans += 2;
            else if(!(cur_row & 120) || !(cur_row & 480) || !(cur_row & 30)) // seat (4 - 7) / (6 - 9) / (2 - 5) are vaccant
                ans ++;

            
            //clear current row
            cur_row = 0;

            ans += 2 * (reservedSeats[i][0] - reservedSeats[i-1][0] - 1);
            cur_row |= 1 << (reservedSeats[i][1] - 1);
        }
        
        if(cur_row){
            //handle current row
            if(!(cur_row & 510)) // if seat 2 - 9 are vaccant
                ans += 2;
            else if(!(cur_row & 120) || !(cur_row & 480) || !(cur_row & 30)) // seat (4 - 7) / (6 - 9) / (2 - 5) are vaccant
                ans ++;            
        }

        ans += 2 * (n - reservedSeats.back()[0]);
        return ans;
    }
};
