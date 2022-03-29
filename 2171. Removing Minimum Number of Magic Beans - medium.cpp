//https://leetcode.com/problems/removing-minimum-number-of-magic-beans/
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());        
        if(beans.front() == beans.back())
            return 0;

        long long higher = 0, lower = 0;
        int prev = beans.front();
        
        for(auto itr = upper_bound(beans.begin(), beans.end(), prev); itr != beans.end(); ++ itr)
            higher += (*itr) - prev;

        long long ops = higher;
        int i = 0, num_lt_cur = beans.size(), cur;
        
        while(1){
            int count = 0;
            
            while(i < beans.size() && beans[i] == prev){
                count ++;
                i ++;
            }
            
            if(i == beans.size()) break;
            
            num_lt_cur -= count;
            lower += (long long)prev * count;
            higher -= (long long)(beans[i] - prev) * num_lt_cur;
            
            ops = min(ops, lower + higher);
            
            prev = beans[i];
        }
        return ops;
    }
};
