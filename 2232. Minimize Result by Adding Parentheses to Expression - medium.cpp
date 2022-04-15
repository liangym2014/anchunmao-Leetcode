// https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/
class Solution {
public:
    string minimizeResult(string expression) {
        size_t pos = expression.find('+');
        
        string left = expression.substr(0, pos);
        vector<pair<int, int>> l(left.size());
        l[0] = {1, stoi(left)};
        for(int i = 1; i < left.size(); i ++){
            l[i] = {stoi(left.substr(0, i)), stoi(left.substr(i))};
        }
        
        vector<int> best_compos(4);
        int mn = INT_MAX, start = pos + 1;
        for(int i = pos + 1; i < expression.size(); i ++){
            int c = stoi(expression.substr(start, i - start + 1)), 
            d = (i + 1 < expression.size())?stoi(expression.substr(i + 1)):1;
            
            for(auto &[a, b]: l){
                int cur = a * (b + c) * d;
                if(cur >= mn)
                    continue;
                mn = cur;
                best_compos = {a, b, c, d};
            }
        }
        
        string ans("(" + to_string(best_compos[1]) + "+" + to_string(best_compos[2]) + ")");
        
        if(to_string(best_compos[2]) == expression.substr(start)){
            if(to_string(best_compos[1]) == left)
                return ans;

            return to_string(best_compos[0]) + ans;
        }
            
        if(to_string(best_compos[1]) == left)
            return ans + to_string(best_compos[3]);
        
        return to_string(best_compos[0]) + ans + to_string(best_compos[3]);
    }
};
