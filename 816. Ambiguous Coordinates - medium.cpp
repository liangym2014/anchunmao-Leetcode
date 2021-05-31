// https://leetcode.com/problems/ambiguous-coordinates/

#include <vector>
#include <string>

class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        if(s.size() == 4){
            return {s.substr(0, 2) + ", " + s.substr(2)};
        }
            
        //remove '(' and ')'
        s = s.erase(0, 1);
        s.pop_back();
        
        vector<string> res;
        
        for(int i = 1; i < s.size(); ++ i){
            if(i > 1 && s.substr(0, i) == string(i, '0'))  // x should not be all 0 and length >=2
                continue;
            
            int remain_len = s.size() - i;
            
            if(remain_len > 1 && s.substr(i, remain_len) == string(remain_len, '0')) // y should not be all 0 and length >=2
                continue;
            
            string x = s.substr(0, i), y = s.substr(i);
            
            vector<string> xs = add_decimal(x); // add decimal point to x
            
            if(xs.empty())
                continue;
            
            vector<string> ys = add_decimal(y); // add decimal point to y
            
            if(ys.empty())
                continue;
            
            for(auto &e1: xs){
                for(auto &e2: ys){
                    res.push_back('(' + e1 + ", " + e2 + ')');  // integrate x and y after adding decimal point

                }
            }
        }
        
        return res;
        
    }
    
    vector<string> add_decimal(string s){
        vector<string> res;
        
        if(s.size() > 1 && s.front() == '0'){
            if(s.back() == '0') //decimal part should not end with 0
                return res;

            s.insert(1, 1, '.');
            return {s};
        }
        else
            res.push_back(s);
        
        for(int i = 1; i < s.size(); ++ i){
            if(s.substr(i).back() == '0')  //decimal part should not end with 0
                break;
            res.push_back(s.substr(0, i) + "." + s.substr(i));
        }
        return res;
    }
};
