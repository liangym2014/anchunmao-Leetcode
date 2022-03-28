// https://leetcode.com/problems/count-collisions-on-a-road/
class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0, start = 0;
        for(int i = 1; i < directions.size(); i ++){
            if(directions[i] == 'S'){
                if(directions[start] == 'R')
                    ans += i - start;
                
                start = i;
            }
            else if(directions[i] == 'L'){
                if(directions[start] == 'L')
                    continue;
                
                if(directions[start] == 'S')
                    ans ++;
                else{  // directions[start] == 'R'
                    ans += i - start + 1;
                    directions[i] = 'S';
                    start = i;
                }
            }
            else if(directions[start] != 'R') // directions[i] == 'R'
                start = i;
        }
        return ans;
    }
};
