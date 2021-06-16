// https://leetcode.com/problems/minimum-number-of-frogs-croaking/

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        if((croakOfFrogs.size() % 5) || croakOfFrogs[0] != 'c' || croakOfFrogs.back() != 'k')
            return -1;
        
        int ans = 0;   // total number of different frogs
        vector<int> chrs(26);

        for(auto &c: croakOfFrogs){
            if(c == 'c'){
                if(ans)
                    ans --;
                
                chrs['c' - 97] ++;
            }
            else if(c == 'r'){
                if(chrs['c' - 97]){
                    chrs['c' - 97] --;
                    chrs['r' - 97] ++;
                }
                else
                    return -1;
            }
            else if(c == 'o'){
                if(chrs['r' - 97]){
                    chrs['r' - 97] --;
                    chrs['o' - 97] ++;
                }
                else
                    return -1;
            }
            else if(c == 'a'){
                if(chrs['o' - 97]){
                    chrs['o' - 97] --;
                    chrs['a' - 97] ++;
                }
                else
                    return -1;
            }
            else if(c == 'k'){
                if(chrs['a' - 97]){
                    chrs['a' - 97] --;
                    ans ++;
                }
                else
                    return -1;
            }            
        }
        //check whether there're unfinished croak
        if(chrs['c' - 97] || chrs['r' - 97] || chrs['o' - 97] || chrs['a' - 97] || chrs['k' - 97])
            return -1;
        
        return ans;
    }
};
