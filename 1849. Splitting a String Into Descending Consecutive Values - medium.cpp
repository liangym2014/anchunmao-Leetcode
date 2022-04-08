// https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/
class Solution {
private:
    vector<unordered_set<unsigned long long>> next;
    vector<int> status;
    
public:
    bool splitString(string s) {
        int n = s.size();
        
        if(n == 1)
            return false;
        
        next.assign(n,unordered_set<unsigned long long>());
        status.assign(n, -1); // undetermined: -1, valid sequence: 1, fail to construct a valid sequence: 0
        f(s, 0);
       
        return status[0];
    }
    
    void f(string &s, int start){
        int n = s.size(), i = start;
        
        while(i < n && s[i] == '0')
            i ++;  // the index of 1st non-zero digit
        
        if(i == n){
            i --;
            next[i].insert(0);
        }
        else if(i)  // ensure two or more non-empty substrings
            next[i].insert(stoull(s.substr(i)));

        for(int j = i, lim = n - 1; j < lim; j ++){
            string cur = s.substr(i, j - i + 1);
            
            if(status[j + 1] < 0)
                f(s, j + 1);
            
            unsigned long long num = stoull(cur);

            if(next[j + 1].count(num - 1)){
                next[i].insert(num);
                status[i] = 1;
            }
        }

        if(status[i] < 0)
            status[i] = 0;  // if can't find a proper next to cur, marked status[i] as fail to construct a valid sequence
        
        while(start < i){   // update "zeros" between start and i with the situation of s[i] 
            next[start] = next[i];
            status[start] = status[i];
            start ++;
        }

    }
};
