//https://leetcode.com/problems/count-number-of-texts/
const int M = 1000000007;

class Solution {
public:
    int countTexts(string pressedKeys) {
        vector<long long> v;
        v.push_back(1);  // empty string
        
        int count = 1;
        v.push_back(1);  // pressedKeys[0]
        
        for(int i = 1; i < pressedKeys.size(); i ++){
            char c = pressedKeys[i];
            if(c != pressedKeys[i - 1])
                count = 1;
            else
                count ++;
            
            long long acc = 0;
            int lim = (c == '7' || c == '9')? min(4, count): min(3, count);
            for(int i = 0; i < lim; i ++)
                acc += *(v.rbegin() + i);
            
            if(v.size() == 4)
                v.erase(v.begin());
            
            v.push_back(acc % M);
        }
        return v.back();
    }
};
