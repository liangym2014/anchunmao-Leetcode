// https://leetcode.com/problems/clumsy-factorial/
class Solution {
public:
    int clumsy(int n) {
        if(n == 1)  return 1;
        if(n == 2)  return 2;
        if(n == 3)  return 6;
        
        int x = (n - 4) / 4;
        int addition = (x + 1) * (n - 3 - 2 * x);

        int md = n * (n - 1) / (n - 2);  // the result of multiplication and division
        n -= 4;
        
        while(n >= 4){
            md -= n * (n - 1) / (n - 2);
            n -= 4;
        }
        
        if(n == 3)
            md -= 6;
        else if(n == 2)
            md -= 2;
        else if(n == 1)
            md -= 1;
        
        return md + addition;
    }
};
