// https://leetcode.com/problems/intervals-between-identical-elements/
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        vector<long long> sum(arr.size(), 0);
        unordered_map<int, vector<int>> m;
        
        for(int i = 0; i < arr.size(); ++ i){
            m[arr[i]].push_back(i);
        }
        
        for(auto &e:m){
            if(e.second.size() == 1)
                continue;
            
            vector<int> *p = &e.second;
            long long n = p->size() - 1;
            long long after = accumulate(p->begin(), p->end(), (long long)0);
            long long before = 0;
            for(int i = 0; i <= n; ++ i){
                long long ele = p->at(i);
                after -= ele;
                sum[ele] = after - (n - i) * ele + ele * i - before;
                before += ele;
            }
        }
        return sum;
    }
};
