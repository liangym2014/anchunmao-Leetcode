// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        
        while(s.size() > 1){
            if(s.back() == '0')
                s.pop_back();
            else{
                int i = s.size() - 1;
                
                for(;i >= 0; -- i){
                    if(s[i] == '1')
                        continue;
                    string suffix(s.size() - i - 1, '0');
                    s.resize(i);
                    s += "1" + suffix;
                    break;
                }
                
                if(i < 0)
                    s = "1" + string(s.size(), '0');
            }
            
            steps ++;
        }
        return steps;
    }
};
